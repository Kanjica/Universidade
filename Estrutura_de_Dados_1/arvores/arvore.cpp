typedef struct Node{
  int data;
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
    if(n>root->data) root->right = insert(root->right, n);
    else
      if(n<root->data) root->left = insert(root->left, n);
      else std::cout << "Repeated." << std::endl;
      return root;
  }
}
