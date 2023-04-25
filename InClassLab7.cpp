#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == nullptr) {
    return;
  }
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == nullptr) {
    struct node *newNode = new struct node;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
  }
  
  if (key < node->key) {
    node->left = insertNode(node->left, key);
  } else if (key > node->key) {
    node->right = insertNode(node->right, key);
  }
  
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == nullptr) {
    return root;
  }
  
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {
    // Node with only one child or no child
    if (root->left == nullptr) {
      struct node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }
    
    // Node with two children
    struct node *minRight = root->right;
    while (minRight->left != nullptr) {
      minRight = minRight->left;
    }
    root->key = minRight->key;
    root->right = deleteNode(root->right, minRight->key);
  }
  
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}