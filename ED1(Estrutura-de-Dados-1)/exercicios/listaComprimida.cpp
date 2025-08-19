#include <iostream>

using namespace std;

struct Nodo {
    int info;
    Nodo* prox;
};

class listaComprimida {
Nodo* inicio;
public:
    listaComprimida() {
        inicio=nullptr;
    }

    Nodo* intercalar(Nodo* x, Nodo* y);
    Nodo* comprimir(Nodo *inicio);
    Nodo* descomprimir(Nodo *inicio);
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

        
        Nodo* noValor = new Nodo{valor, nullptr};
        
        Nodo* noCont = new Nodo{cont, nullptr};

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
Nodo* listaComprimida::descomprimir(Nodo* inicio){
    if (inicio == nullptr) return nullptr;

    Nodo* atual = inicio;
    Nodo* novaLista = nullptr;
    Nodo* fim = nullptr;

    while (atual != nullptr && atual->prox != nullptr){
        int valor = atual->info;
        int quantidade = atual->prox->info;

        for (int i=0; i < quantidade; i++){
            Nodo* novo = new Nodo{valor, nullptr};
            if (novaLista == nullptr){
                novaLista = novo;
                fim = novo;
            }
            else{
                fim->prox = novo;
                fim = novo;
            }
        }

        atual = atual->prox->prox; 
    }

    return novaLista;
}
