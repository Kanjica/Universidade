#include <iostream>

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
};

int main() {
    Arvore arv;
    Node* novoNo = new Node(10);
    arv.setRaiz(novoNo);

    std::cout << "Raiz: " << arv.raiz->data << std::endl;
    return 0;
}
