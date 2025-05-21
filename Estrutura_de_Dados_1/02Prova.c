#include <iostream>

using namespace std;

void limparTela(){ 
    cout << "\033[2J\033[1;1H";
}

struct Nodo{
    int info; 
    Nodo *prox, *ant;
};

class Lista{
public:
    Nodo* inicio;
    Lista(){
        inicio = nullptr;
    }
  
    void add(int n);
    void remover(int n); 
    void printarElementos();
    void removerAntesDepois(int n);
};

void Lista::add(int n){
    Nodo* novo = new Nodo();
    novo->info = n;
    novo->prox = nullptr;
    novo->ant = nullptr;
    
    if(inicio == nullptr){
        inicio = novo;
    } 
    else{
        Nodo* atual = inicio;
        while(atual->prox != nullptr){
            atual = atual->prox;
        }
        atual->prox = novo;
        novo->ant = atual;
    }
}

void Lista::remover(int n){
    if(inicio == nullptr) return;
    
    
}
void Lista::printarElementos(){
    if(inicio == nullptr){cout << "Lista vazia!" << endl;return;}

    Nodo* atual = inicio;
    cout << "Lista: ";
    while(atual != nullptr) {
        cout << atual->info << " ";
        atual = atual->prox;
    }
    cout << endl;
}


void Lista::removerAntesDepois(int n){
    if(inicio == nullptr) return;

    Nodo* atual = inicio;
    
    while(atual != nullptr){
        if(atual->info == n){
            if(atual->ant != nullptr){
                Nodo* aux = atual->ant;
                if(aux == inicio){ inicio = atual; }
		    
                atual->ant = aux->ant;
                if(aux->ant != nullptr){ aux->ant->prox = atual; }
		    
                delete aux;
            }
            
            if(atual->prox != nullptr){
                Nodo* aux = atual->prox;
                atual->prox = aux->prox;
                if(aux->prox != nullptr){ aux->prox->ant = atual; }
                delete aux;
            }
        }
        atual = atual->prox;
    }
}

int main(){
    Lista lista = new Lista();


    return 0;
}
