#ifndef RBTree_HPP_
#define RBTree_HPP_ 1
#include "binary_search_tree.hpp"

namespace Trees{

template<class Key,class Value>class RBTree;

enum Color { RED, BLACK };

template<class Key,class Value>
class RBTNode : public BinaryNode<Key,Value>{
friend RBTree<Key,Value>;
public:
  Key key;
  Value val;
  Color color;
  BinaryNode<Key,Value>* root,*left,*right,*parent;
  /*Default constructor. Should assign the default value to key and value
  */
  BinaryNode();
  /*This contructor should assign the key and val from the passed parameters
  */
  BinaryNode(Key key, Value value);
};

/* The color enumeration.
 * Please use this and not integers or characters to store the color of the node
 * in your red black tree.
 * Also create a class RBTNode which should inherit from BinaryNode and has the attribute color in it. 
 */

template <class Key, class Value>
class RBTree : public BSTree<Key, Value> {
/* Inherit as many functions as possible from BSTree.
 * Only override those which absolutely need it.
 * Also make sure that all inherited functions work correctly in the context of a red black tree.
 * node_ptr in the following piece of code refers to a pointer to the node you may be using for your red black tree.
 * Use a typedef to refer to a pointer to your node via node_ptr
 */

	/* Function insertRBFixup
	 *
	 * Used for:
	 * Used after an insertion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
	 */
	void insertRBFixup(RBTree<Key,Value>* root,);

/* Function deleteRBFixup
	 * Used for:
	 * Used after a deletion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
	 */
	void deleteRBFixup(RBTree<Key,Value>* root);

public:
	/* Function : blackHeight
	 * 
	 * Returns:
	 * the black height of the red black tree which begins at node_ptr root
	 */
	int blackHeight(RBTree<Key,Value>* root);	
	/*
	 * Apart from these functions, also provide functions for rotations in the tree.
	 * The signature of the rotation functions is omitted to provide you flexibility in how you implement the internals of your node.
	 */
};


template<class Key,class Value>
void RBTree :: rotateLeft(RBTNode<Key,Value>*& root,RBTNode<Key,Value>*& pt){

    RBTNode<Key,Value>* pt_right = pt->right;
 
    pt->right = pt_right->left;
 
    if (pt->right != NULL){
        pt->right->parent = pt;
    }
 
    pt_right->parent = pt->parent;
 
    if (pt->parent == NULL){
        root = pt_right;
    }
 
    else if (pt == pt->parent->left){
        pt->parent->left = pt_right;
    }
 
    else{
        pt->parent->right = pt_right;
    }
 
    pt_right->left = pt;
    pt->parent = pt_right;

}
 
template<class Key,class Value> 
void RBTree :: rotateRight(RBTNode<Key,Value>*& root,RBTNode<Key,Value>*& pt){
    
    RBTNode<Key,Value>* pt_left = pt->left;

    pt->left = pt_left->right;
 
    if (pt->left != NULL){
        pt->left->parent = pt;
    }
 
    pt_left->parent = pt->parent;
 
    if (pt->parent == NULL){
        root = pt_left;
    }
 
    else if (pt == pt->parent->left){
        pt->parent->left = pt_left;
    }
 
    else{
        pt->parent->right = pt_left;
    }
 
    pt_left->right = pt;
    pt->parent = pt_left;
}


// This function fixes violations caused by BST insertion
template<class Key,class Value>
void RBTree :: fixViolation(RBTree<Key,Value>*& root,RBTree<Key,Value>*& pt){

    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;
 
    while ((pt != root) && (pt->color != BLACK) &&(pt->parent->color == RED)){
 
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;
 
        /*  Case : A
            Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left){
 
            Node *uncle_pt = grand_parent_pt->right;
 
            /* Case : 1
               The uncle of pt is also red
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color == RED){
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
 
            else{
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == parent_pt->right){

                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;

                }
 
                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;

            }
        }
 
        /* Case : B
           Parent of pt is right child of Grand-parent of pt */
        else{
            Node *uncle_pt = grand_parent_pt->left;
 
            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)){

                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else{
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left){

                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                
                }
                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

// Function to insert a new node with given data
template<class Key,class Value>
void RBTree :: insert(RBTree<Key,Value>* node,Key key,Value value){

    RBTree<Key,Value>* pt = newNode(key,value);
 
    // Do a normal BST insert
    root = BSTInsert(root, pt);
 
    // fix Red Black Tree violations
    fixViolation(root, pt);
}




//end of namespace
}


#endif /* ifndef RBTree_HPP_ */