#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int valor) : data(valor), left(nullptr), right(nullptr) {}
    Node() : data(0), left(nullptr), right(nullptr) {}
};

class Arvore {
public:
    Node* raiz;

    Arvore(): raiz(nullptr) {}

    void inserir(int valor){
        raiz = inserirRec(raiz, valor);
    }

    void exibirEmOrdem(){
        exibirEmOrdemRec(raiz);
    }

    bool buscar(int valor){
        return buscarRec(raiz, valor) != nullptr;
    }

private:
    Node* inserirRec(Node* raiz, int valor) {
        if(!raiz){
            return new Node(valor);
        }
    
        if(valor < raiz->data){
            raiz->left = inserirRec(raiz->left, valor); 
        } 
        else if(valor > raiz->data){
            raiz->right = inserirRec(raiz->right, valor); 
        }
        else{
            cout << "Valor duplicado ignorado: " << valor << endl;
        }
        return raiz; 
    }

    void exibirEmOrdemRec(Node* raiz){
        if(!raiz) return;

        exibirEmOrdemRec(raiz->left);
        cout << raiz->data << " " <<endl;
        exibirEmOrdemRec(raiz->right);
    }

    Node* buscarRec(Node* raiz, int valor){
        if(!raiz || raiz->data == valor) return raiz;
        if(valor < raiz->data) return buscarRec(raiz->left, valor);
        else return buscarRec(raiz->right, valor);
    }
};

int main() {
    Arvore arv;
    
    arv.inserir(10);
    arv.inserir(5);
    arv.inserir(15); 
    arv.inserir(3); 
    arv.inserir(7); 
    arv.inserir(12); 
    arv.inserir(18); 

    arv.exibirEmOrdem();

    cout << "Buscar 7: " << (arv.buscar(7) ? "Encontrado" : "Não encontrado") << endl;
    cout << "Buscar 99: " << (arv.buscar(99) ? "Encontrado" : "Não encontrado") << endl;

    return 0;
}
