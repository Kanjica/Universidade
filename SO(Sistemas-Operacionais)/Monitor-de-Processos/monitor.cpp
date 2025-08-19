#define UNICODE
#define _UNICODE
#define _WIN32_WINNT 0x0601

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <stdlib.h>

#if !defined(_countof)
#define _countof(array) (sizeof(array)/sizeof(array[0]))
#endif

//////////////////////////////////////////////////////////
//g++ monitor.cpp -o monitor.exe -lsapi -lAdvapi32
//////////////////////////////////////////////////////////

typedef struct {
    ULONGLONG lastProcessKernelTime;
    ULONGLONG lastProcessUserTime;
    ULONGLONG lastSystemKernelTime;
    ULONGLONG lastSystemUserTime;
} PROCESS_CPU_DATA;

DWORD* g_aProcesses = NULL;
PROCESS_CPU_DATA* g_cpuDataArray = NULL;
DWORD g_cProcesses = 0;

int GetCPUCoreCount() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    return sysInfo.dwNumberOfProcessors;
}

double CalculateCPUUsage(HANDLE hProcess, PROCESS_CPU_DATA* previous) {
    FILETIME ftCreation, ftExit, ftKernel, ftUser;
    FILETIME ftSysIdle, ftSysKernel, ftSysUser;

    if (!GetProcessTimes(hProcess, &ftCreation, &ftExit, &ftKernel, &ftUser))
        return -1.0;

    if (!GetSystemTimes(&ftSysIdle, &ftSysKernel, &ftSysUser))
        return -1.0;

    ULONGLONG processKernel = (((ULONGLONG)ftKernel.dwHighDateTime << 32) | ftKernel.dwLowDateTime);
    ULONGLONG processUser = (((ULONGLONG)ftUser.dwHighDateTime << 32) | ftUser.dwLowDateTime);
    ULONGLONG systemKernel = (((ULONGLONG)ftSysKernel.dwHighDateTime << 32) | ftSysKernel.dwLowDateTime);
    ULONGLONG systemUser = (((ULONGLONG)ftSysUser.dwHighDateTime << 32) | ftSysUser.dwLowDateTime);

    if (previous->lastProcessKernelTime == 0 && previous->lastProcessUserTime == 0) {
        previous->lastProcessKernelTime = processKernel;
        previous->lastProcessUserTime = processUser;
        previous->lastSystemKernelTime = systemKernel;
        previous->lastSystemUserTime = systemUser;
        return -1.0;
    }

    ULONGLONG procTimeDelta = (processKernel - previous->lastProcessKernelTime) +
                              (processUser - previous->lastProcessUserTime);
    ULONGLONG sysTimeDelta = (systemKernel - previous->lastSystemKernelTime) +
                             (systemUser - previous->lastSystemUserTime);

    previous->lastProcessKernelTime = processKernel;
    previous->lastProcessUserTime = processUser;
    previous->lastSystemKernelTime = systemKernel;
    previous->lastSystemUserTime = systemUser;

    if (sysTimeDelta == 0)
        return 0.0;

    int numCores = GetCPUCoreCount();
    double usage = ((double)procTimeDelta / sysTimeDelta) * 100.0 * numCores;

    if (usage < 0.0)
        usage = 0.0;

    return usage;
}

DWORD GetThreadCount(DWORD processID) {
    HANDLE hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    THREADENTRY32 te32;
    DWORD threadCount = 0;

    if (hThreadSnap != INVALID_HANDLE_VALUE) {
        te32.dwSize = sizeof(THREADENTRY32);
        if (Thread32First(hThreadSnap, &te32)) {
            do {
                if (te32.th32OwnerProcessID == processID) {
                    threadCount++;
                }
            } while (Thread32Next(hThreadSnap, &te32));
        }
        CloseHandle(hThreadSnap);
    }
    return threadCount;
}

void PrintProcessInfo(DWORD processID, double cpuUsage) {
    TCHAR szProcessPath[MAX_PATH] = TEXT("<unknown>");
    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");
    HANDLE hProcess = NULL;
    PROCESS_MEMORY_COUNTERS_EX pmc = {0};
    DWORD threadCount = 0;
    BOOL hasBasicInfo = FALSE;
    BOOL hasMemoryInfo = FALSE;

    DWORD accessFlags[] = {
        PROCESS_QUERY_LIMITED_INFORMATION | PROCESS_VM_READ,
        PROCESS_QUERY_LIMITED_INFORMATION,
        PROCESS_QUERY_INFORMATION
    };

    for (int i = 0; i < _countof(accessFlags) && !hProcess; i++) {
        hProcess = OpenProcess(accessFlags[i], FALSE, processID);
    }

    if (hProcess != NULL) {
        DWORD dwSize = _countof(szProcessPath);
        if (QueryFullProcessImageName(hProcess, 0, szProcessPath, &dwSize)) {
            TCHAR* pFileName = _tcsrchr(szProcessPath, TEXT('\\'));
            _sntprintf(szProcessName, _countof(szProcessName), TEXT("%s"), pFileName ? pFileName + 1 : szProcessPath);
            hasBasicInfo = TRUE;
        }

        if (GetProcessMemoryInfo(hProcess, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
            hasMemoryInfo = TRUE;
        }

        CloseHandle(hProcess);
    }

    threadCount = GetThreadCount(processID);

    if (hasBasicInfo) {
        _tprintf(TEXT("%-40s   PID: %-8u"), szProcessName, processID);

        if (cpuUsage >= 0.0) {
            _tprintf(TEXT("   CPU: %7.3f%%"), cpuUsage);
        } else {
            _tprintf(TEXT("   CPU: %7s"), TEXT("N/A  "));
        }

        if (hasMemoryInfo) {
            _tprintf(TEXT("   Mem: %8zu KB"),
                   pmc.WorkingSetSize / 1024);
        } else {
            _tprintf(TEXT("   Mem: %8s"), TEXT("N/A"));
        }

        _tprintf(TEXT("   Threads: %3d\n"), threadCount);
    } else {
        _tprintf(TEXT("%-40s   PID: %-8u   [Acesso negado]\n"),
               TEXT("<unknown>"), processID);
    }
}

void AtualizarListaProcessos() {
    if (g_aProcesses) {
        free(g_aProcesses);
        g_aProcesses = NULL;
    }
    if (g_cpuDataArray) {
        free(g_cpuDataArray);
        g_cpuDataArray = NULL;
    }

    DWORD aProcesses[1024];
    DWORD cbNeeded;
    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
        _tprintf(TEXT("Erro ao enumerar processos: %u\n"), GetLastError());
        g_cProcesses = 0;
        return;
    }

    g_cProcesses = cbNeeded / sizeof(DWORD);
    g_aProcesses = (DWORD*)malloc(sizeof(DWORD) * g_cProcesses);
    g_cpuDataArray = (PROCESS_CPU_DATA*)calloc(g_cProcesses, sizeof(PROCESS_CPU_DATA));
    if (!g_aProcesses || !g_cpuDataArray) {
        _tprintf(TEXT("Erro ao alocar memoria\n"));
        g_cProcesses = 0;
        if (g_aProcesses) free(g_aProcesses);
        if (g_cpuDataArray) free(g_cpuDataArray);
        return;
    }
    memcpy(g_aProcesses, aProcesses, sizeof(DWORD) * g_cProcesses);
}

void MostrarProcessos() {
    if (!g_aProcesses || g_cProcesses == 0) {
        _tprintf(TEXT("Lista de processos vazia. Atualize a lista primeiro.\n"));
        return;
    }

    for (DWORD i = 0; i < g_cProcesses; i++) {
        if (g_aProcesses[i] != 0) {
            HANDLE h = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, g_aProcesses[i]);
            if (h) {
                CalculateCPUUsage(h, &g_cpuDataArray[i]);
                CloseHandle(h);
            }
        }
    }

    Sleep(500); 

   _tprintf(TEXT("\n%-40s      %-10s      %9s      %9s      %7s\n"),
         TEXT("Nome do Processo"), TEXT("PID"), TEXT("CPU%"), TEXT("Memory"), TEXT("Threads"));
    _tprintf(TEXT("-----------------------------------------------------------------------------------------------------------\n"));
    
    for (DWORD i = 0; i < g_cProcesses; i++) {
        if (g_aProcesses[i] != 0) {
            HANDLE h = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, g_aProcesses[i]);
            if (h) {
                double usage = CalculateCPUUsage(h, &g_cpuDataArray[i]);
                PrintProcessInfo(g_aProcesses[i], usage);
                CloseHandle(h);
            }
        }
    }
}

BOOL EncerrarProcessoPorPID(DWORD processID) {
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processID);
    if (hProcess == NULL) {
        _tprintf(TEXT("Falha ao abrir processo PID %u. Código do erro: %u\n"), processID, GetLastError());
        return FALSE;
    }

    BOOL result = TerminateProcess(hProcess, 1); 
    if (!result) {
        _tprintf(TEXT("Falha ao encerrar processo PID %u. Código do erro: %u\n"), processID, GetLastError());
    } else {
        _tprintf(TEXT("Processo PID %u encerrado com sucesso.\n"), processID);
    }

    CloseHandle(hProcess);
    return result;
}

int main() {

    int opcao = 0;

    AtualizarListaProcessos();

    do {
        _tprintf(TEXT("=== Menu de Monitoramento de Processos ===\n"));
        _tprintf(TEXT("1. Exibir processos e uso de CPU\n"));
        _tprintf(TEXT("2. Atualizar lista de processos\n"));
        _tprintf(TEXT("3. Encerrar processo por PID\n"));
	_tprintf(TEXT("4. Sair\n"));
        _tprintf(TEXT("Escolha uma opcao: "));

        if (scanf_s("%d", &opcao) != 1) {
            while (getchar() != '\n'); 
            opcao = 0;
        }

        switch (opcao) {
            case 1:
	        system("cls");
                MostrarProcessos();
                printf("\nPressione qualquer tecla para voltar ao menu...\n");
                getchar(); getchar(); 
                break;
            case 2:
		system("cls");
                AtualizarListaProcessos();
		MostrarProcessos();
                _tprintf(TEXT("\nLista atualizada com %u processos.\n"), g_cProcesses);
                printf("Pressione qualquer tecla para voltar ao menu...\n");
                getchar(); getchar();
                break;
            case 3:
		DWORD pid;
    		_tprintf(TEXT("Digite o PID do processo que deseja encerrar: "));
    		_tscanf(TEXT("%u"), &pid);
		
    		if (pid == 0) {
        		_tprintf(TEXT("PID inválido.\n"));
        	return -1;
    		}

    		if (EncerrarProcessoPorPID(pid)) {
        		_tprintf(TEXT("Processo %u encerrado com sucesso.\n"), pid);
    		} 
		else {
        		_tprintf(TEXT("Falha ao encerrar processo %u.\n"), pid);
    		}
		system("cls");	

		break;
	    case 4:
                _tprintf(TEXT("Saindo...\n"));
                break;
            default:
                _tprintf(TEXT("Opcao invalida. Tente novamente.\n"));
                printf("Pressione qualquer tecla para voltar ao menu...\n");
                getchar(); getchar();
        }
    } while (opcao != 4);

    if (g_aProcesses) free(g_aProcesses);
    if (g_cpuDataArray) free(g_cpuDataArray);

    return 0;
}
