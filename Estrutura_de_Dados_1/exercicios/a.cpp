//Inserção Ordenada
//Implemente uma função que insere um elemento de forma ordenada em uma lista simplesmente encadeada.
#include <iostream>

struct Nodo {
    int info;
    Nodo* prox;
};

class insercaoOrdenada{
public:
Nodo* inicio;

  insercaoOrdenada(){
    inicio=nullptr;
  }  

  void inserir(Nodo* inicio);
}

void insercaoOrdenada::inserir(int nig){
  
  Nodo *novo = new Nodo(), *ant;
  Nodo *atual = inicio;
  
  novo->info = nig;
  novo->prox = nullptr;
  
  while(atual!=nullptr && (atual->info > nig)){
    ant = atual;
	  atual = atual->prox;
  }
  if(atual == nullptr){
      atual->prox = novo;
  }
  else{
    if(atual == inicio){
      novo->prox = atual;
      inicio = novo;
    }
    else{
      ant->prox = novo;
      novo->prox = atual;
    }
  }
}
