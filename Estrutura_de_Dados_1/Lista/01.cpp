//Escreva funções, em C, que recebam uma lista simplesmente encadeada
//ordenada, e realizem as seguintes operações:

//a. retirar todos os elementos ímpares que são primos, e, gerar uma
//outra lista contendo apenas os elementos retirados da lista inicial,
//em ordem decrescente:

//b. retirar todos os elementos pares da lista inicial.

struct Nodo{
  int info;
  Nodo *prox;
};

class Lista{
Nodo* inicio;
public:
  Lista(){
    inicio = nullptr;
  }

  Nodo *fA(Nodo *inicio);
  Nodo *fB(Nodo *inicio);
};

Nodo* Lista::fA(Nodo*inicio){
  if (inicio == nullptr){return nullptr;}

  Nodo* atual = inicio;
  Nodo* novaLista = nullptr;
  Nodo* auxNovaLista, * ant;
  
  int cont;
  while(atual!=nullptr){
    //testando se é primo
    cont = 0;
    if(atual->info != 0 && atual->info != 1)
    for(int i = 3; i<atual->info; i+=2){
      if(atual->info%i == 0){break;cont = 1;}
    }

    //adicionando na lista
    if(cont==0 && atual->info != 0 && atual->info != 1){
      if(novaLista == nullptr){
        novaLista = atual;
        auxNovaLista = novaLista;
      }
      else{
        auxNovaLista->prox = atual
        auxNovaLista = auxNovaLista->prox;
      }
    }
    //removendo da principal
    if(cont==0 && atual->info != 0 && atual->info != 1){
      if(ant!=nullptr){
        ant->prox = atual->prox;
      }
      else{
        inicio = atual->prox;
      }
    }
    ant = atual;
    atual = atual->prox;
  }

  //ordenanado 
  auxNovaLista = novaLista;
  while(auxNovaLista->prox!=nullptr){
    if(auxNovaLista->info > auxNovaLista->prox->info){
      Nodo* aux2 = auxNovaLista->prox;
      auxNovaLista->prox = auxNovaLista;
      auxNovaLista = aux;
    }
    auxNovaLista = auxNovaLista->prox;
  }
}

Nodo* Lista::fB(Nodo*inicio){
  if(inicio == nullptr)return nullptr;
  
  Nodo* atual = inicio *ant = nullptr;
  while(atual != nullptr){
    if(atual->info%2 == 0){
      if(ant!=nullptr){ant->prox = atual->prox;}
      else{inicio = atual ->prox;}
    }
    ant = atual;
    atual = atual->prox;
  }
}
