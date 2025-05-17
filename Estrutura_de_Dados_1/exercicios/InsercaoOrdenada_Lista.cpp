//Inserção Ordenada
//Implemente uma função que insere um elemento de forma ordenada em uma lista simplesmente encadeada.
#include <iostream>

struct Nodo {
    int info;
    Nodo* prox;
};

class Lista{
public:
Nodo* inicio;

  Lista(){
    inicio=nullptr;
  }  

  void inserir(int nig);
};

void Lista::inserir(int nig){
  
  Nodo *novo = new Nodo(), *ant = nullptr;
  Nodo *atual = inicio;
  
  novo->info = nig;
  novo->prox = nullptr;

	if(inicio == nullptr){
		inicio = novo;
		return;
	}
  while(atual!=nullptr && (atual->info < nig)){
    ant = atual;
	  atual = atual->prox;
  }
  if(atual == nullptr){
      ant->prox = novo;
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
