#include <iostream>

struct Nodo {
	int info;
	struct Nodo *prox;
}

class listaOrdenada {
	Nodo *inicio;

	listaOrdenada() {
		inicio = nullptr;
	}

	void add(int n) {
		Nodo *novo, *atual, *ant;
		novo->info = n;
		novo = new Nodo();
		if (inicio ==nullptr) {
			inicio->prox = nullptr;
			inicio = novo;
		}
		else {
			atual = inicio;
			while((atual!=nullptr) && (atual->info < novo->info)) {
				ant = atual;
				atual = atual->prox;
			}
		}
	}

	bool remover(int n) {
		Nodo *atual, *ant;

		atual = inicio;
		while((atual!=nullptr) && (atual->info != n) {
		ant = atual;
		atual = atual->prox;
	    }

    	if(atual==nullptr) {
    		return false;
    	}
        
    	if(atual->info == n) {
    		ant->prox = atual->prox;
    		return true;
    	}
    	
    }
}
