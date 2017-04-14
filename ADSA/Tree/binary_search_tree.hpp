#ifndef BSTREE_HPP
#define BSTREE_HPP 1
#include "binary_tree.hpp"

namespace Trees{

//template<class Key,class Value> class BinaryTree;
//template<class Key,class Value> class BinaryNode;

template<class Key,class Value>
class BSTree : public BinaryTree<Key,Value>{

private:
  BinaryTree<Key,Value>* node;
/* Inherit as many functions as possible from BinaryTree.
 * Only override those where you can decrease the time complexity and where you absolutely need to do it.
 * Also make sure that all inherited functions work correctly in the context of a binary search tree.
 */
protected:
  //this is the way to access the protected variables or methods of base class into derived class
  //access declarations are deprecated in favour of using-declarations; suggestion: add the ‘using’ keyword so use "using BinaryTree<Key,Value> :: root;"
  //instead of just "BinaryTree<Key,Value> :: root;"
  using BinaryTree<Key,Value> :: root;

  BinaryNode<Key,Value>* insert(BinaryNode<Key,Value>* root,Key key,Value val);

  Value search_and_give(BinaryNode<Key,Value>* root,Key key);

  bool search(BinaryNode<Key,Value>* root,Key key);

  Key find_successor(BinaryNode<Key,Value>* node,Key key);

  Key find_predecessor(BinaryNode<Key,Value>* node,Key key);

public:
  /* Binary Search Tree default constructor
  */
  BSTree();
  /* Implement get function to retrieve the value corresponding to given key in binary tree.
   */
  Value get(const Key& key);
  /* Implement remove function that can delete a node in binary tree with given key. 
   */
  //virtual void remove(const Key& key) ;
  /* Implement has function which will return true if the given key is present in binary tree 
   * otherwise return false.  
   */
  virtual bool has(const Key& key) ;  
  /* Implement put function such that newly inserted node keep the tree balanced. 
   */ 
  virtual void put(const Key& key, const Value& value) ;
  
  virtual Key minimum();
  /*
   * This method returns the maximum element in the binary tree.
   */
  virtual Key maximum();
  /*
   *This method returns the successor, i.e, the next larget element in the
   *binary tree, after Key.
   */
  virtual Key successor(const Key& key);
  /*
   * This method returns the predessor, ie, the next smallest element in the
   * binary tree, after Key.
   */
  virtual Key predecessor(const Key& key);
  /*
   * This method returns the current height of the binary search tree.
   */
  //virtual int getHeight();
  /*
   * This method returns the total number of elements in the binary search tree.
   */
  //virtual int size();
  /*
   * This method prints the key value pairs of the binary search tree, sorted by
   * their keys.
   */
  //virtual void print();

};

template<class Key,class Value>
  BSTree<Key,Value> :: BSTree(){ 
  root = NULL;
}

template<class Key,class Value>
void BSTree<Key,Value> :: put(const Key& key, const Value& value){
  root = insert(root,key,value);
}

template<class Key,class Value>
BinaryNode<Key,Value>* BSTree<Key,Value> :: insert(BinaryNode<Key,Value>* root,Key k,Value v){
  
  if(root == NULL){
    return this -> newNode(k,v);
  }

  if( root-> key > k){
    root -> left = insert(root->left,k,v);
  }
  if(root -> key < k){
    root -> right = insert(root->right,k,v);
  }

  return root;

}

template<class Key,class Value>
Value BSTree<Key,Value> :: get(const Key& key){

  return search_and_give(root,key);

}

template<class Key,class Value>
Value BSTree<Key,Value> :: search_and_give(BinaryNode<Key,Value>* root,Key key){
  
  if(root != NULL){

    if(root -> key == key){
      return root -> val;
    }

    if(root -> key > key){
      return search_and_give( root -> left,key);
    }
    else{
      return search_and_give(root -> right,key);
    }

  }

  return 0;              //TODO  fix this
}

template<class Key,class Value>
bool BSTree<Key,Value> :: has(const Key& key){

  return search(root,key);

}

template<class Key,class Value>
bool BSTree<Key,Value> :: search(BinaryNode<Key,Value>* root,Key key){

  if(root != NULL){

    if(root -> key == key){
      return true;
    }

    if(root -> key > key){
      return search_and_give( root -> left,key);
    }
    else{
      return search_and_give(root -> right,key);
    }
  }

  return false;              //TODO  
}

template<class Key,class Value>
Key BSTree<Key,Value> :: maximum(){

  BinaryNode<Key,Value>* temp = root;

  if(root != NULL){

    while(temp -> right != NULL){
      temp = temp -> right;
    }

  }

  return temp -> val;

}

template<class Key,class Value>
Key BSTree<Key,Value> :: minimum(){

  BinaryNode<Key,Value>* temp = root;
  
  if(root != NULL){

    while(temp -> left != NULL){
      temp = temp -> left;
    }

  }

  return temp -> val;

}

template<class Key,class Value>
Key BSTree<Key,Value> :: successor(const Key& key){

  return find_successor(root,key);

}

template<class Key,class Value>
Key BSTree<Key,Value> :: find_successor(BinaryNode<Key,Value>* root,Key key){

  if(root == NULL){
    return 0;
  }

  if(root != NULL){

    if(root -> key == key){

      if(root -> right != NULL){

        BinaryNode<Key,Value>* temp_left = root -> right;

        while(temp_left -> left != NULL){
          temp_left = temp_left -> left;
        }

        return temp_left -> key;

      }

    }

  }

}

template<class Key,class Value>
Key BSTree<Key,Value> :: predecessor(const Key& key){

  return find_predecessor(root,key);

}

template<class Key,class Value>
Key BSTree<Key,Value> :: find_predecessor(BinaryNode<Key,Value>* root,Key key){

  if(root == NULL){
    return 0;
  }

  if(root != NULL){

    if(root -> key == key){

      if(root -> left != NULL){

        BinaryNode<Key,Value>* temp_right = root -> left;

        while(temp_right -> right!= NULL){
          temp_right = temp_right -> right;
        }

        return temp_right -> key;

      }

    }

  }

}



//end of namespace  
}




#endif /* ifndef BSTREE_HPP */