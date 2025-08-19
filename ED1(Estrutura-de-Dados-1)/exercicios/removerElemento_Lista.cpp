//Remover Elemento
//Escreva uma função que remove todas as ocorrências de um valor específico da lista.

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
  void remover(int nig);
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

void Lista::remover(int nig){
  if(inicio == nullptr)return;
  Nodo* atual = inicio->prox, *ant = inicio, *aux;

  if(inicio->info == nig){
    aux = inicio;
    inicio = inicio->prox;
    delete(aux)
  }
  while (atual != nullptr) {
        if (atual->info == nig){
            aux = atual;
            ant->prox = atual->prox;
            atual = atual->prox; 
            delete aux;
        } 
        else{
            ant = atual;
            atual = atual->prox;
        }
    }
}
