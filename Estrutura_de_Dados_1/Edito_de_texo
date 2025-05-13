#include <iostream>

void limparTela(){ //função q achei na net pra limpar a tela, uma alternativa p n usar system
    std::cout << "\033[2J\033[1;1H";
}

struct Nodo {
	char *info;
	struct Nodo *prox, *ant;
};

class listaCircular {
	Nodo *inicio, *fim;
	int posPalavra;
    int qtdPalavra;

public:
	listaCircular() {
		inicio = nullptr;
		fim = nullptr;
		posPalavra = -1;
        qtdPalavra = 0;
	}

	char* palavraAtual();
	void imprimirFrase();
	void editar();
	void add(char *palavra);
	void remover();
	void palavraAnterior();
	void palavraPosterior();
	void setPosPalavra(int i){
	    this->posPalavra = i;
	}
};

char* listaCircular::palavraAtual() {
	Nodo *atual;

	if(inicio == nullptr) return nullptr;

	atual = inicio;

	for(int i = 0; i < posPalavra; i++) {
		atual = atual->prox;
	}

	return atual->info;
}

void listaCircular::imprimirFrase() {
	Nodo *atual;

	if (inicio == nullptr) return;
    
    std::cout << std::endl;
	atual = inicio;
	do {
		std::cout << atual->info << " ";
		atual = atual->prox;
	} while (atual != inicio);
	std::cout << std::endl;
}

void listaCircular::editar() {
	Nodo *atual;

	if (inicio == nullptr) return;

	atual = inicio;

	for (int i=0; i<posPalavra; i++) {
		atual = atual->prox;
	}

	std::cout << "\nDigite a nova palavra: ";
	std::cin >> atual->info;
}

void listaCircular::add(char *palavra ) {
	Nodo *novo, *atual, *anterior; 
	
	novo = new Nodo();
    atual = inicio;
	anterior = nullptr;

	novo->info = new char[50];
	
	int ru = 0;
	while(palavra[ru]!= '\0'){
	    novo->info[ru] = palavra[ru];
	    ru++;
	}
    novo->info[ru] = '\0';
    
	if(inicio == nullptr){
		inicio = novo;
		inicio->prox = inicio;
		inicio->ant = inicio;
		fim = inicio;
		(qtdPalavra)++;
	}
	else {
		atual = inicio;

		if(posPalavra>0)
			for(int i=0; i<posPalavra; i++){
				anterior = atual;
				atual = atual->prox;
			}
	    
		if(anterior == nullptr) anterior = inicio->ant;
	
		novo->ant = anterior;
		novo->prox = atual;
		anterior->prox = novo;
		atual->ant = novo;
	    
		if(atual == inicio && posPalavra == 0){
			inicio = novo;
		}

		(qtdPalavra)++;

	}
}

void listaCircular::remover( ){
	Nodo *atual = inicio;
	Nodo *anterior = nullptr;

	if(inicio == nullptr) return;

	for (int i = 0; i < posPalavra; i++){
		anterior = atual;
		atual = atual->prox;
	}

	if (atual == inicio && atual->prox == inicio){
		delete atual->info;
		delete atual;
		inicio = nullptr;
		fim = nullptr;
		qtdPalavra = 0;
		return;
	}

	anterior = atual->ant;
	anterior->prox = atual->prox;
	atual->prox->ant = anterior;

	if (atual == inicio) inicio = atual->prox;
	if (atual == fim) fim = anterior;

	delete[] atual->info;
	delete atual;

	(qtdPalavra)--;

	if (qtdPalavra == 0) {
		inicio = nullptr;
		fim = nullptr;
	}

	if(posPalavra >= qtdPalavra) posPalavra = 0;
}

void listaCircular::palavraAnterior(  ) {
	(posPalavra)--;
	if(posPalavra == -1) posPalavra = qtdPalavra - 1;
}

void listaCircular::palavraPosterior(  ) {
	(posPalavra)++;
	if(posPalavra == qtdPalavra) posPalavra = 0;
}


int main() {
	listaCircular editor;
	char action = 'a';
	char palavraNova[50];

	editor.add((char*)"Lorem" );
	editor.add((char*)"ipsum" );
	editor.add((char*)"dolor" );
    editor.add((char*)"sit" );
	editor.add((char*)"amet" );
	
	editor.setPosPalavra((int)0);
	
	while (1) {
		editor.imprimirFrase();
		std::cout << "\nPalavra atual: " << editor.palavraAtual() << std::endl;
		std::cout << "          E: editar palavra atual" << std::endl;
		std::cout << "          D: inserir (antes da palavra atual)" << std::endl;
		std::cout << "          S: eliminar palavra" << std::endl;
		std::cout << "          <: palavra anterior" << std::endl;
		std::cout << "          >: palavra posterior" << std::endl;
		std::cout << "          X: sair" << std::endl;
		std::cout << "          Escolha: ";

		std::cin >> action;

		/*
		char* palavraAtual();
		void imprimirFrase();
		void editar();
		void add(char *palavra, int *qtdPalavra);
		void remover(int *qtdPalavra);
		void palavraAnterior(int *posPalavra, int *qtdPalavra);
		void palavraPosterior(int *posPalavra, int *qtdPalavra);
		*/
		switch (action) {
		case 'E':
			editor.editar();
			break;

		case 'D':
			std::cout << "Nova palavra: ";
			std::cin >> palavraNova;

			editor.add(palavraNova );
			break;

		case 'S':
			editor.remover( );
			break;

		case '<':
			editor.palavraAnterior(  );
			break;

		case '>':
			editor.palavraPosterior(  );
			break;

		case 'X':
			return 0;

		default:
			std::cout << "deu bo" << std::endl;
			break;
		}
		limparTela();
	}

	return 0;
}
