typedef struct Node{
  int value;
  struct Node *left, *right;
}Node;

class BinaryTree{
  public:
    Node* root;
  
    Node* insert(Node* root, int n);
    Node* in_order(Node* root);
};

BinaryTree::BinaryTree(){
  root = nullptr;
  
  Node* insert(Node* root, int n){
    if(root == nullptr){
      root = new Node();
      if(root == nullptr) exit(1);

      root->info = n;
      root->left = nullptr;
      root->right = nullptr;

      return root;
    }
    if(n>root->value) root->right = insert(root->right, n);
    else
      if(n<root->value) root->left = insert(root->left, n);
      else std::cout << "Repeated.";
      return root;
  }

void insertIterative(Nodo* root, int n){
  Nodo* current, *parent;
  if(root==nullptr){
    root = new Node();
    if(root == nullptr) exit(1);
  
    root->info = n;
    root->left = nullptr;
    root->right = nullptr;
    return;
  }
  current = root;
  while(current!=nullptr){
    parent = current;
    if(n>current->value) current = current->right;
    else 
      if(n < current->value) current = current->left;
      else std::cout << "Repeated.";
  }
  current = new Node();
  if(!current) exit(1);

  current->value = n;
  current->left = nullptr;
  current->right = nullptr;

  if(n>parent->value) parent->right = current;
  else parent->left = current;
  }
}
