//Concatenar Listas
//Implemente uma função que recebe duas listas e retorna uma nova lista com os elementos das duas.

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
  Nodo* concatenar(Nodo *x, Nodo*y);
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

Nodo* Lista::concatenar(Nodo *x, Nodo *y){
    if(x == nullptr) return y;

    Nodo* atual = x;
    while(atual->prox != nullptr){
        atual = atual->prox;
    }
    atual->prox = y;
    return x;
}
