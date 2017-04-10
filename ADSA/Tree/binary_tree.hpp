#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP 1


namespace BT{

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
class BinaryTree
{
  /* You can implement your own helper functions whenever required.
   */
  //accessible to classes which inherit from BinaryTree
protected:
  
  BinaryNode<Key,Value>* root;

  //helper function for in order traversal
  void in_order(BinaryNode<Key,Value>* root);

  //helper function for pre order traversal
  void pre_order(BinaryNode<Key,Value>* root);

  //helper function for post order traversal
  void post_order(BinaryNode<Key,Value>* root);

  BinaryNode<Key,Value>* newNode(Key key,Value val);


public:
  /* Binary tree default constructor
  */
  BinaryTree();
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
  //virtual void put(const Key& key, const Value& value) ;
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

};


template<class Key,class Value>
BinaryNode<Key,Value> :: BinaryNode(){
  key = 0;
  val = 0;
  root = NULL;
  left = NULL;
  right = NULL;
  parent = NULL;
}  

template<class Key,class Value>
BinaryNode<Key,Value> :: BinaryNode(Key k,Value v){
  key = k;
  val = v;
  root = NULL;
  left = NULL;
  right = NULL;
  parent = NULL;
}


template<class Key,class Value>
BinaryTree<Key,Value> :: BinaryTree(){
  root = NULL;
}

template<class Key,class Value>
BinaryNode<Key,Value>* BinaryTree<Key,Value> :: newNode(Key k,Value v){

  BinaryNode<Key,Value>* newTempNode = new BinaryNode<Key,Value>();
  newTempNode -> key = k;
  newTempNode -> val = v;
  newTempNode -> left = NULL;
  newTempNode -> right = NULL;

}


template<class Key,class Value>
void BinaryTree<Key,Value> :: in_order(BinaryNode<Key,Value>* root){
  if(root!=NULL){
    in_order(root->left);
    std::cout<<root->key<<" "<<root->val<<std::endl;
    in_order(root->right);
  }
}

template<class Key,class Value>
void BinaryTree<Key,Value> :: pre_order(BinaryNode<Key,Value>* root){
  if(root!=NULL){
    std::cout<<root->key<<" "<<root->val<<std::endl;
    pre_order(root->left);
    pre_order(root->right);
  }
}

template<class Key,class Value>
void BinaryTree<Key,Value> :: post_order(BinaryNode<Key,Value>* root){
  if(root!=NULL){
    post_order(root->left);
    post_order(root->right);
    std::cout<<root->key<<" "<<root->val<<std::endl;
  }
}

template<class Key,class Value>
void BinaryTree<Key,Value> :: print_in_order(){
  in_order(root);
}

template<class Key,class Value>
void BinaryTree<Key,Value> :: print_post_order(){
  post_order(root);
}

template<class Key,class Value>
void BinaryTree<Key,Value> :: print_pre_order(){
  pre_order(root);
}

//end of namespace BT  
}

#endif /* ifndef BINARYTREE_HPP */