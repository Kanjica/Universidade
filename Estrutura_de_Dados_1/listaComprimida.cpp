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
