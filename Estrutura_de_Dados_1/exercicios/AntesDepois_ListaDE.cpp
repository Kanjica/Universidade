#include <iostream>

struct Nodo {
    int info;
    Nodo* prox, *ant;
};

class Lista(){
  public:
  Nodo* inicio;
  Lista(){
    inicio = nullptr;
  }
  void antesN(int n, int novoValor);
  void depoisN(int n, int novoValor);
}

void Lista::antesN(int n, int novoValor){
  Nodo* novo = new Nodo();
  novo->info = novoValor;
  novo->prox = nullptr;
  novo->ant = nullptr;

  if (inicio == nullptr) {
      inicio = novo;
      return;
  }

  Nodo* atual = inicio;
  Nodo* ante = nullptr;

  while (atual != nullptr && atual->info != n) {
      ante = atual;
      atual = atual->prox;
  }

  if (atual == nullptr) {
      ante->prox = novo;
      novo->ant = ante;
  } else {
      if (atual == inicio) {
          novo->prox = inicio;
          inicio->ant = novo;
          inicio = novo;
      } else {
          ante->prox = novo;
          novo->ant = ante;
          novo->prox = atual;
          atual->ant = novo;
      }
  }
}

void Lista::depoisN(int n, int novoValor){
    Nodo *atual = inicio;
    
    while (atual != nullptr && atual->info != n){
        atual = atual->prox;
    }

    if (atual == nullptr){return;}

    Nodo *novo = new Nodo();
    novo->info = novoValor;

    novo->prox = atual->prox;
    novo->ant = atual;

    if (atual->prox != nullptr){
        atual->prox->ant = novo;
    }
    atual->prox = novo;
}
