#ifndef AVLTREE_HPP
#define AVLTREE_HPP 1
#include <vector>

namespace Trees{

template<class Key,class Value>class BinaryTree;

template<class Key,class Value>
class BinaryNode{
friend BinaryTree<Key,Value>;
public:
  Key key;
  Value val;
  BinaryNode<Key,Value>*left,*right,*parent;
  int height;
  /*Default constructor. Should assign the default value to key and value
  */
  BinaryNode();
  /*This contructor should assign the key and val from the passed parameters
  */
  BinaryNode(Key key, Value value);
};


template<class Key,class Value>
class AVLTree
{

public:
  /* You can implement your own helper functions whenever required.
  */
  //accessible to classes which inherit from BinaryTree
protected:

  BinaryNode<Key,Value>* root;

  std::vector<BinaryNode<Key,Value>*> queue;
  
  //helper function for in order traversal
  void in_order(BinaryNode<Key,Value>* root);

  //helper function for pre order traversal
  void pre_order(BinaryNode<Key,Value>* root);

  //helper function for post order traversal
  void post_order(BinaryNode<Key,Value>* root);

  BinaryNode<Key,Value>* newNode(Key& key,Value& val);

  void insert(Key key,Value value,std::vector<BinaryNode<Key,Value>*>& queue);

  bool search(BinaryNode<Key,Value>* root,const Key key);

  Value get_Value(BinaryNode<Key,Value>* root,Key key);

  int get_size(BinaryNode<Key,Value>* root);


public:
  /* Binary tree default constructor
  */
  BinaryTree();
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
  virtual void put(const Key& key, const Value& value);
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
   * This method returns the total number of elements in the binary search tree.
   */
  virtual int size();

  virtual void print();

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
BinaryNode<Key,Value>* BinaryTree<Key,Value> :: newNode(Key& k,Value& v){

  BinaryNode<Key,Value>* newTempNode = new BinaryNode<Key,Value>();
  newTempNode -> key = k;
  newTempNode -> val = v;
  newTempNode -> left = NULL;
  newTempNode -> right = NULL;

  return newTempNode;

}

template<class Key,class Value>
void BinaryTree<Key,Value> :: put(const Key& key, const Value& value){

  //std::cout<<"Hii"<<std::endl;
  insert(key,value,queue);

}

template<class Key,class Value>
void BinaryTree<Key,Value> :: insert(Key key,Value value,std::vector<BinaryNode<Key,Value>*>& queue){

    // Create a new node for given data
    BinaryNode<Key,Value>* temp = newNode(key,value);
 
    // If the tree is empty, initialize the root with new node.
    if(!root){
      root = temp;
    }else{
    // get the front node of the queue.
    BinaryNode<Key,Value>* front = queue.front();
    // If the left child of this front node doesn’t exist, set the
    // left child as the new node
    if(!front->left)
      front->left = temp;
    // If the right child of this front node doesn’t exist, set the
    // right child as the new node
    else if(!front->right)
      front->right = temp;
      // If the front node has both the left child and right child,
      // Dequeue() it.
    if(front && front->left && front->right)
      queue.erase(queue.begin());
    }
 
    // Enqueue() the new node for later insertions
    queue.push_back(temp);
}

template<class Key,class Value>
Value BinaryTree<Key,Value> :: get(const Key& key){

  return get_Value(root,key);

}

template<class Key,class Value>
Value BinaryTree<Key,Value> :: get_Value(BinaryNode<Key,Value>* root,Key key){
  
  if(root == NULL){
    return false;
  }

  if(root -> key == key){
    return root -> val;
  }else if(search(root -> left,key)){
    return get_Value(root -> left,key);
  }else if(search(root -> right,key)){
    return get_Value(root -> right,key);
  }

}

template<class Key,class Value>
bool BinaryTree<Key,Value> :: has(const Key& key){

  search(root,key);

}

template<class Key,class Value>
bool BinaryTree<Key,Value> :: search(BinaryNode<Key,Value>* root,const Key key){
  
  if(root == NULL){
    return false;
  }

  if(root -> key == key){
    true;
  }else{
    return search(root -> left,key) or search(root -> right,key);
  }

}

template<class Key,class Value>
Key BinaryTree<Key,Value> :: minimum(){

  if(root == NULL){
    return 0;
  }

  Key min = root -> key;
  std::vector<BinaryNode<Key,Value>*> iterator;
 
  iterator.push_back(root);
 
  while(!iterator.empty()){
    BinaryNode<Key,Value>* temp = iterator.front();
    iterator.erase(iterator.begin());
    (min > temp -> key ? min = temp -> key : min = min ); 
 
    if (temp->left){
      iterator.push_back(temp -> left);
    }
 
    if (temp->right){      
      iterator.push_back(temp -> right);
    }

  }

  return min;

}

template<class Key,class Value>
Key BinaryTree<Key,Value> :: maximum(){

  if(root == NULL){
    return 0;
  }

  Key max = root -> key;
  std::vector<BinaryNode<Key,Value>*> iterator;
 
  iterator.push_back(root);
 
  while(!iterator.empty()){
    BinaryNode<Key,Value>* temp = iterator.front();
    iterator.erase(iterator.begin());
    (max < temp -> key ? max = temp -> key : max = max ); 
 
    if (temp->left){
      iterator.push_back(temp -> left);
    }
 
    if (temp->right){      
      iterator.push_back(temp -> right);
    }

  }

  return max;
}

template<class Key,class Value>
Key BinaryTree<Key,Value> :: successor(const Key& key){

  if(root == NULL){
    return 0;
  }

  Key diff = 100000;
  Key least_diff;
  std::vector<BinaryNode<Key,Value>*> iterator;
 
  iterator.push_back(root);
 
  while(!iterator.empty()){

    BinaryNode<Key,Value>* temp = iterator.front();
    iterator.erase(iterator.begin());
    least_diff = temp -> key - key;

    (diff > least_diff && least_diff>0 ? diff = least_diff : diff = diff); 
 
    if (temp->left){
      iterator.push_back(temp -> left);
    }
 
    if (temp->right){      
      iterator.push_back(temp -> right);
    }

  }

  if( diff == 100000){
    return 0;
  }

  return diff+key;

}

template<class Key,class Value>
Key BinaryTree<Key,Value> :: predecessor(const Key& key){

  if(root == NULL){
    return 0;
  }

  Key diff = -10000;
  Key least_diff;
  std::vector<BinaryNode<Key,Value>*> iterator;
 
  iterator.push_back(root);
 
  while(!iterator.empty()){

    BinaryNode<Key,Value>* temp = iterator.front();
    iterator.erase(iterator.begin());
    least_diff = temp -> key - key;

    (diff < least_diff && least_diff<0 ? diff = least_diff : diff = diff); 
 
    if (temp->left){
      iterator.push_back(temp -> left);
    }
 
    if (temp->right){      
      iterator.push_back(temp -> right);
    }

  }

  if(diff == -10000){
    return 0;
  }

  return diff+key;

}

template<class Key,class Value>
void BinaryTree<Key,Value> :: print(){
  
  Key max;
  std::vector<BinaryNode<Key,Value>*> iterator;
 
  iterator.push_back(root);
 
  while (iterator.empty()){
    BinaryNode<Key,Value>* temp = iterator.front();
    iterator.erase(iterator.begin());
    
    std::cout<<temp -> key<<" ";
 
    if(temp->left){
      iterator.push_back(temp -> left);
    }
 
    if(temp->right){      
      iterator.push_back(temp -> right);
    }
  }
  
  std::cout<<std::endl;

}

template<class Key,class Value>
int BinaryTree<Key,Value> :: size(){
  return get_size(root); 
}

template<class Key,class Value>
int BinaryTree<Key,Value> :: get_size(BinaryNode<Key,Value>* root){
  if(root == NULL){
    return 0;
  }

  int left_size = get_size(root -> left);
  int right_size = get_size(root -> right);

  return left_size + right_size + 1;

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

//end of namespace  
}

#endif /* ifndef BINARYTREE_HPP */