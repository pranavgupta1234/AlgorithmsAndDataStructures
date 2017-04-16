#ifndef AVL_HPP
#define AVL_HPP 1
#include "binary_search_tree.hpp"

namespace Trees{

template <class Key,class Value>
class AVL : public BSTree<Key, Value>{
private:


protected:
  using BinaryTree<Key,Value> :: root;

  /*
   * Inherit as much functionality as possible from the BSTree class.
   * Then provide custom AVL Tree functionality on top of that.
   * The AVL Tree should make use of as many BST functions as possible.
   * Override only those methods which are extremely necessary.
   */
  /*
   * Apart from that, your code should have the following four functions:
   * getBalance(node) -> To get the balance at any given node;
   * doBalance(node) -> To fix the balance at the given node;
   * rightRotate(node) -> Perform a right rotation about the given node.
   * leftRotate(node) -> Perform a left rotation about the given node.
   *
   * The signature of these functions are not provided in order to provide you
   * some flexibility in how you implement the internals of your AVL Tree. But
   * make sure these functions are there.
  */

  // A utility function to get height of the tree
  int height(BinaryNode<Key,Value>* node);

  /* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
  BinaryNode<Key,Value>* newNode(Key key,Value value);

  //A utility function to right rotate subtree rooted with y
  BinaryNode<Key,Value>* rightRotate(BinaryNode<Key,Value>* y);

  // A utility function to left rotate subtree rooted with x
  // See the diagram given above.
  BinaryNode<Key,Value> *leftRotate(BinaryNode<Key,Value>* x);

  // Get Balance factor of node N
  int getBalance(BinaryNode<Key,Value>* node);

  // Recursive function to insert key in subtree rooted
  // with node and returns new root of subtree.
  BinaryNode<Key,Value>* insert(BinaryNode<Key,Value>* node,Key key,Value value);



public:

  virtual void put(const Key& key, const Value& value);

  int max_val(int a,int b);

}; 
 
template<class Key,class Value>
int AVL<Key,Value> :: height(BinaryNode<Key,Value>* node){
  if (node == NULL)
    return 0;
  return node -> height;
}
 
template<class Key,class Value>
BinaryNode<Key,Value>* AVL<Key,Value> :: newNode(Key key,Value value){

  BinaryNode<Key,Value>* node = new BinaryNode<Key,Value>();
  node->key     = key;
  node->val     = value;
  node->left    = NULL;
  node->right   = NULL;
  node->height  = 1;  // new node is initially added at leaf

  return(node);

}

template<class Key,class Value>
int AVL<Key,Value> :: max_val(int a,int b){
  return (a > b ? a : b);
}

template<class Key,class Value>
BinaryNode<Key,Value>* AVL<Key,Value> :: rightRotate(BinaryNode<Key,Value>* y){

  BinaryNode<Key,Value>* x = y->left;
  BinaryNode<Key,Value>* T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max_val(height(y->left), height(y->right))+1;
    x->height = max_val(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}

template<class Key,class Value>
BinaryNode<Key,Value>* AVL<Key,Value> :: leftRotate(BinaryNode<Key,Value>* x){

    BinaryNode<Key,Value>* y = x->right;
    BinaryNode<Key,Value>* T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max_val(height(x->left), height(x->right))+1;
    y->height = max_val(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
template<class Key,class Value>
int AVL<Key,Value> :: getBalance(BinaryNode<Key,Value>* node){
  if (node == NULL){
    return 0;
  }
  return height(node->left) - height(node->right);
}

template<class Key,class Value>
void AVL<Key,Value> :: put(const Key& key, const Value& value){
  root = insert(root,key,value);
}
 
template<class Key,class Value>
BinaryNode<Key,Value>* AVL<Key,Value> :: insert(BinaryNode<Key,Value>* node, Key key,Value value){

  /* 1.  Perform the normal BST insertion */
  if(node == NULL){
    return(newNode(key,value));
  }
 
  if(key < node->key){
    node->left  = insert(node->left,key,value);
  }
  else if (key > node->key){
    node->right = insert(node->right, key,value);
  }
  else{
    // Equal keys are not allowed in BST
    return node;
  } 
 
  /* 2. Update height of this ancestor node */
  node->height = 1 + max_val(height(node->left),height(node->right));
 
  /* 3. Get the balance factor of this ancestor
  node to check whether this node became
  unbalanced */
  int balance = getBalance(node);
 
  // If this node becomes unbalanced, then
  // there are 4 cases
 
  // Left Left Case
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);
 
  // Right Right Case
  if (balance < -1 && key > node->right->key)
    return leftRotate(node);
 
  // Left Right Case
  if (balance > 1 && key > node->left->key){
    node->left =  leftRotate(node->left);
    return rightRotate(node);
  }
 
  // Right Left Case
  if (balance < -1 && key < node->right->key){
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
 
  /* return the (unchanged) node pointer */
  return node;

} 


//end of namespace
}



#endif /* ifndef AVL_HPP */