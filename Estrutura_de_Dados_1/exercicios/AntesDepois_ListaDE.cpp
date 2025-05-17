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
  if(inicio==nullptr) return;
  Nodo* novo = new Nodo();
  
  novo->info = n;
  novo->prox == nullptr;
  novo->ant == nullptr;
  
  Nodo* atual = inicio, *ante=nullptr;
  atual->ant = ante;
  ante->prox = atual;
  
  while(atual!=nullptr && atual->info !=n){
    atual->ant = ante;
    ante->prox = atual;

    ante = ante->prox;
    atual = atual->prox;
  }
  
}
void Lista::depoisN(int n){}
