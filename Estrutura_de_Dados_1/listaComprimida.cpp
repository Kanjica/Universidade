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
    Nodo* fim = nullptr, 
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
    Nodo* novaLista, *atual, *aux, *ant;
    bool a = true;
    if(inicio==nullptr) return nullptr;

    atual = inicio;
    while(atual != nullptr){
        ant=inicio;
        while(ant->prox!=atual && atual != inicio){
            ant = ant->prox;
        }
        if(ant!=atual || (ant==atual && ant == inicio)){
            Nodo* quant = new Nodo();
            
            quant->prox = atual->prox;
            atual->prox = quant;
            
            if(atual->prox->info == atual->info && !a){
                aux = atual->prox;
                
                while(aux==atual){
                    quant->info++;
                    aux = aux->prox;
                    }
                }
            else{
                a = true;
                quant->info++;
            }
        }
    atual = atual->prox;
    }
}
