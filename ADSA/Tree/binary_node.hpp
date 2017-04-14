#ifndef BINARYNODE_HPP
#define BINARYNODE_HPP 1


namespace BN{

template<class Key,class Value>class BinaryTree;

template<class Key,class Value>
class BinaryNode{
friend BinaryTree<Key,Value>;
public:
  Key key;
  Value val;
  BinaryNode<Key,Value>* root,*left,*right,*parent;
  /*Default constructor. Should assign the default value to key and value
  */
  BinaryNode();
  /*This contructor should assign the key and val from the passed parameters
  */
  BinaryNode(Key key, Value value);
};


//end of namespace BN
}

#endif /* ifndef BINARYNODE_HPP */