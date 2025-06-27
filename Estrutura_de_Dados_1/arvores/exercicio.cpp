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

    Arvore() {
        raiz = nullptr;
    }

    void setRaiz(Node* no) {
        raiz = no;
    }

    Node* inserir(Node* raiz, int valor) {
    if(!raiz){
        return new Node(valor);
    }

    if(valor < raiz->data){
        raiz->left = inserir(raiz->left, valor); 
    } 
    else if(valor > raiz->data){
        raiz->right = inserir(raiz->right, valor); 
    }
    else{
        cout << "Valor duplicado ignorado: " << valor << endl;
    }
    return raiz; 
}

};

int main() {
    Arvore arv;
    Node* novoNo = new Node(10);
    arv.setRaiz(novoNo);
    
    arv.inserir(arv.raiz, 5);
    
    cout << "Raiz: " << arv.raiz->data << endl;
    return 0;
}
