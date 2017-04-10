#ifndef BSTREE_HPP
#define BSTREE_HPP 1

namespace BST{

template<class Key,class Value>
class BinaryNode
{
public:
  Key key;
  Value val;
  BinaryNode<Key,Value> * root,* left,* right,* parent;
    /*Default constructor. Should assign the default value to key and value
     */
  BinaryNode();
  /*This contructor should assign the key and val from the passed parameters
     */
  BinaryNode(Key key, Value value);
};

template<class Key,class Value>
class BSTree : public BinaryTree<Key,Value>{

private:
  BinaryTree<Key,Value>* node;
/* Inherit as many functions as possible from BinaryTree.
 * Only override those where you can decrease the time complexity and where you absolutely need to do it.
 * Also make sure that all inherited functions work correctly in the context of a binary search tree.
 */
protected:

  BinaryNode<Key,Value>* insert(BinaryNode<Key,Value>* root,Key key,Value val);

public:
  /* Binary Search Tree default constructor
  */
  BSTree();
  /* Implement get function to retrieve the value corresponding to given key in binary tree.
   */
  //Value get(const Key& key);
  /* Implement remove function that can delete a node in binary tree with given key. 
   */
  //virtual void remove(const Key& key) ;
  /* Implement has function which will return true if the given key is present in binary tree 
   * otherwise return false.  
   */
  //virtual bool has(const Key& key) ;  
  /* Implement put function such that newly inserted node keep the tree balanced. 
   */ 
  virtual void put(const Key& key, const Value& value) ;
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in an in order traversal.
   */
  virtual void print_in_order();
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in an pre order traversal.
   */
  virtual void print_pre_order();
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in a post order traversal.
   */
  virtual void print_post_order();
  /*
   *This method returns the minimum element in the binary tree.
   */
  //virtual Key minimum();
  /*
   * This method returns the maximum element in the binary tree.
   */
  //virtual Key maximum();
  /*
   *This method returns the successor, i.e, the next larget element in the
   *binary tree, after Key.
   */
  //virtual Key successor(const Key& key);
  /*
   * This method returns the predessor, ie, the next smallest element in the
   * binary tree, after Key.
   */
  //virtual Key predecessor(const Key& key);
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
void BSTree<Key,Value> :: put(const Key& key, const Value& value){
  root = insert(root,key,value);
}

template<class Key,class Value>
BinaryNode<Key,Value>* BSTree<Key,Value> :: insert(BinaryNode<Key,Value>* root,Key k,Value v){
  if(root == NULL){
    return newNode(k,v);
  }

  if( root-> key > k){
    root -> left = insert(root->left,k,v);
  }
  if(root -> key < k){
    root -> right = insert(root->right,k,v);
  }
  return root;
}


//end of namespace  
}




#endif /* ifndef BSTREE_HPP */