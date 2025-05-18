//Escreva funções, em C, que recebam uma lista simplesmente encadeada
//ordenada, e realizem as seguintes operações:

//a. retirar todos os elementos ímpares que são primos, e, gerar uma
//outra lista contendo apenas os elementos retirados da lista inicial,
//em ordem decrescente:

//b. retirar todos os elementos pares da lista inicial.

#include <iostream>

struct Nodo {
    int info;
    Nodo *prox;
};

class Lista {
    Nodo* inicio;
public:
    Lista() {
        inicio = nullptr;
    }

    Nodo* fA(Nodo *inicio);
    Nodo* fB(Nodo *inicio);
};

bool ehPrimo(int n){
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}

Nodo* Lista::fA(Nodo *inicio){
    if(inicio == nullptr) return nullptr;

    Nodo *atual = inicio;
    Nodo *novaLista = nullptr;
    Nodo *auxNovaLista = nullptr;
    Nodo *ant = nullptr;
  
    while(atual != nullptr){
        bool ehPrimoImpar = (atual->info % 2 != 0) && ehPrimo(atual->info);

        if (ehPrimoImpar){

            Nodo *novoNo = new Nodo;
            novoNo->info = atual->info;
            novoNo->prox = novaLista;
            novaLista = novoNo;

            if(ant == nullptr){
                inicio = atual->prox;
            }
            else{
                ant->prox = atual->prox;
            }
            Nodo *prox = atual->prox;
            delete atual; 
            atual = prox;
        } 
        else{
            ant = atual;
            atual = atual->prox;
        }
    }
    return novaLista;
}

Nodo* Lista::fB(Nodo *inicio){
    if(inicio == nullptr) return nullptr;
  
    Nodo *atual = inicio;
    Nodo *ant = nullptr;
  
    while(atual != nullptr){
        if(atual->info % 2 == 0){
            if(ant == nullptr){
                inicio = atual->prox;
            } 
            else{
                ant->prox = atual->prox;
            }
            Nodo *prox = atual->prox;
            delete atual; 
            atual = prox;
        }
        else{
            ant = atual;
            atual = atual->prox;
        }
    }
    return inicio;
}
