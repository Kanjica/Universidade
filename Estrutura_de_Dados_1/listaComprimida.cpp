#include <iostream>

using namespace std;

struct Nodo {
    int info;
    Nodo* prox;
};

class listaComprimida {
public:
    listaComprimida() {}

    Nodo* intercalar(Nodo* x, Nodo* y);
    Nodo* comprimir(Nodo *inicio);
};

Nodo* listaComprimida::intercalar(Nodo* x, Nodo* y) {
    Nodo* z = nullptr;
    Nodo* fim = nullptr;
    Nodo* ax,* ay;

    if (x == nullptr) {
        z = y;
    } else if (y == nullptr) {
        z = x;
    } else {
        while ((x != nullptr) && (y != nullptr)) {
            ax = x;
            x = x->prox;
            ay = y;
            y = y->prox;

            ax->prox = ay;
            ay->prox = nullptr;

            if (z == nullptr) {
                z = ax;
                fim = ay;
            } else {
                fim->prox = ax;
                fim = ay;
            }
        }
        if (x == nullptr) {
            fim->prox = y;
        } else {
            fim->prox = x;
        }
    }
    return z;
}
Nodo* listaComprimida::comprimir(Nodo *inicio){
    if (inicio == nullptr) return nullptr;

    Nodo* novaLista = nullptr;
    Nodo* fim = nullptr;
    Nodo* atual = inicio;

    while (atual != nullptr) {
        int valor = atual->info;
        int cont = 0;

        while (atual != nullptr && atual->info == valor) {
            cont++;
            atual = atual->prox;
        }

        // Criar nó do valor
        Nodo* noValor = new Nodo{valor, nullptr};
        // Criar nó da contagem
        Nodo* noCont = new Nodo{cont, nullptr};

        // Inserir na nova lista
        if (novaLista == nullptr) {
            novaLista = noValor;
            noValor->prox = noCont;
            fim = noCont;
        } else {
            fim->prox = noValor;
            noValor->prox = noCont;
            fim = noCont;
        }
    }

    return novaLista;
}
