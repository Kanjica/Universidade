#include <iostream>

using namespace std;

void limparTela(){ 
    std::cout << "\033[2J\033[1;1H";
}

struct Nodo {
	char *info;
	struct Nodo *prox, *ant;
};

class Lista(){
  public:
  Nodo* inicio;
  Lista(){
    inicio = nullptr;
    inicio->prox = nullptr;
    inicio->ant = nullptr;
  }
  
  void add(int n);
  void printarElementos();
  void removerAntesDepois(int n);
}

void Lista::add(int n){
   if(inicio == nullptr){
     inicio->info = n;
   }
   else{
     Nodo* atual = inicio;
     while(atual != nullptr){}
   }
}

void Lista::printarElementos(){
  if(inicio == nullptr) return;

  Nodo* atual = inicio;
  
  while(atual!=nullptr){
    
  }
}

void Lista::removerAntesDepois(int n){
  if(inicio == nullptr) return;

  Nodo* atual = inicio;
  Nodo* antecessor = nullptr;

  while(atual!= nullptr)
}

int main(void){
  Lista lista = new Lista();

  //menu
  return 0;
}
