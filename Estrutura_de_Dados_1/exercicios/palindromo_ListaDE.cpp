//Verificar Palíndromo
//Dada uma lista duplamente encadeada de caracteres, verifique se ela forma um palíndromo.
#include <iostream>

struct Nodo {
    char info;
    Nodo* prox, *ant;
};

class Lista{
  public:
  int tamanho;
  Nodo* inicio, *fim;
  Lista(){
    inicio = nullptr;
    fim = nullptr;
    tamanho = 0;
  }
  void addChar(char c);
  bool isPalindromo();
}
void Lista::addChar(char c){
  Nodo* atual = inicio, *anterior = nullptr;
  
  Nodo *novo = new Nodo();
  novo->info = c;
  novo->prox = nullptr;
  novo->ant = nullptr;
  
  if(inicio == nullptr){
    inicio = novo;
    fim = novo;
    return;
  }
  
  whle(atual->prox!=nullptr){
    anterior = atual;
    atual = atual->prox;
    atual->ant = anterior;
    tamanho++;
  }
  fim = atual;
 
  atual->prox = novo;
  novo->ant = atual;
  fim = novo;
  tamanho+=2;

}

bool Lista::isPalindromo(){
  if(inicio == nullptr){return;}
  
  Nodo* auxInicio = inicio, auxFim = fim;
  for(int i=0; i<tamanho i++){
    if(auxInicio->info != auxFim->info){ std::cout<<"Não é palíndromo." std::endl;return;}

    auxInicio = auxInicio->prox;
    auxFim = auxFim->ant;
  }
  
  std::cout << "É palíndromo." std::endl; return;
}
