#include <iostream>
#include <cstdlib>

typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

class BinaryTree {
public:
    Node* root;

    BinaryTree();

    Node* insert(Node* root, int n);
    void insertIterative(int n);
    void in_order(Node* root);
    bool isIB(Node* root); 
    Node* removeElement(int n);
};

BinaryTree::BinaryTree() {
    root = nullptr;
}

Node* BinaryTree::insert(Node* root, int n) {
    if (root == nullptr) {
        root = new Node();
        if (root == nullptr) exit(1);

        root->value = n;
        root->left = nullptr;
        root->right = nullptr;

        return root;
    }
    if (n > root->value)
        root->right = insert(root->right, n);
    else if (n < root->value)
        root->left = insert(root->left, n);
    else
        std::cout << "Repeated.\n";

    return root;
}

void BinaryTree::insertIterative(int n) {
    Node* current, *parent;
    if (root == nullptr) {
        root = new Node();
        if (root == nullptr) exit(1);

        root->value = n;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    current = root;
    while (current != nullptr) {
        parent = current;
        if (n > current->value)
            current = current->right;
        else if (n < current->value)
            current = current->left;
        else {
            std::cout << "Repeated.\n";
            return;
        }
    }
    current = new Node();
    if (!current) exit(1);

    current->value = n;
    current->left = nullptr;
    current->right = nullptr;

    if (n > parent->value)
        parent->right = current;
    else
        parent->left = current;
}

void BinaryTree::in_order(Node* root) {
    if (root == nullptr) return;
    in_order(root->left);
    std::cout << root->value << " ";
    in_order(root->right);
}

bool BinaryTree::isIB(Node* root) {
    if (root == nullptr) return true;

    if ((root->left == nullptr && root->right == nullptr) ||
        (root->left != nullptr && root->right == nullptr))
        return (isIB(root->left) && isIB(root->right));
    else
        return false;
}

Node* BinaryTree::removeElement(int n){
    Node* temp;
    if(root == nullptr)return root;
    
    if(n > root->value)root->right = removeElement(n);
    else{
        if(n < root->value) root->right = removeElement(n);
        else
            if(root->left == nullptr){
                temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            else
                if(root->right == nullptr){
                    temp = root;
                    root = root->left;
                    delete temp;
                    return root;
                }
        
    }
}
int main(void) {
    BinaryTree tree;

    tree.root = tree.insert(tree.root, 10);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 15);
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 13);

    std::cout << "In-order: ";
    tree.in_order(tree.root);
    std::cout << "\n";

    if (tree.isIB(tree.root))
        std::cout << "The tree matches the IB condition.\n";
    else
        std::cout << "The tree does NOT match the IB condition.\n";

    return 0;
}
