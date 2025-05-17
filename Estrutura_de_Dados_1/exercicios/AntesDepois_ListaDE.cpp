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
  void antesN(int n);
  void depoisN(int n);
}

void Lista::antesN(int n){
  Nodo* novo = new Nodo();
  novo->info = n;
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
      // n n encontrado
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

void Lista::depoisN(int n){}
