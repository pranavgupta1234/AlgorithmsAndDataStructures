#ifndef RBTree_HPP_
#define RBTree_HPP_ 1
#include "binary_search_tree.hpp"
#include "limits.h"


namespace Trees{
/* The color enumeration.
 * Please use this and not integers or characters to store the color of the node
 * in your red black tree.
 * Also create a class RBTNode which should inherit from BinaryNode and has the attribute color in it. 
 */
enum Color { RED, BLACK };

template <class Key,class Value>
class RBTree : public BSTree<Key,Value>{
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
	void insertRBFixup(BinaryNode<Key,Value>* z);

/* Function deleteRBFixup
	 * Used for:
	 * Used after a deletion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
	 */
	void deleteRBFixup(BinaryNode<Key,Value>* rt);

	int blackHeight(BinaryNode<Key,Value>* rt);
	void left_rotate(BinaryNode<Key,Value>* z);
	void right_rotate(BinaryNode<Key,Value>* z);

public:
	/* Function : blackHeight
	 * 
	 * Returns:
	 * the black height of the red black tree which begins at node_ptr root
	 */	

		void put(const Key& key, const Value& value);
		int blackHeight();
		void remove(const Key& key);
		int color(Key key);
	/*
	 * Apart from these functions, also provide functions for rotations in the tree.
	 * The signature of the rotation functions is omitted to provide you flexibility in how you implement the internals of your node.
	 */
};


template<class Key, class Value>
void RBTree<Key,Value> :: put(const Key& key, const Value& value){

	BSTree<Key,Value> :: put(key,value);
	BinaryNode<Key,Value>* node = this->getNode(key);

	node->color=RED;

	insertRBFixup(node);
}	



template <class Key, class Value> 
void RBTree<Key,Value> :: insertRBFixup(BinaryNode<Key,Value>*  node){

	BinaryNode<Key,Value> *parent, *grandParent, *uncle;	
	if(node == this->root){
		this->root->color = BLACK;
	}
	else{
		
		while(node)
		{

			parent = node->parent;

			if(!parent)
				break;

			grandParent = parent->parent;

			//When parent is root
			if(!grandParent){
				break;
			}

			//When a parent of node is black
			if(parent->color != RED){
				break;
			}

			//When parent is left node of grand parent
			if (parent == grandParent->left)
			{
				uncle  = grandParent->right;
				if(uncle){
					//When uncle is red
					if(uncle->color == RED){

						parent->color = BLACK;
						uncle->color = BLACK;
						grandParent->color=RED;
						node = grandParent;
					}
					else{ 
						//When the newly inserted node is at right
						if(node->key > parent->key){
							left_rotate(parent);
						}
										
						node->color = BLACK;
						grandParent->color = RED;
						right_rotate(grandParent);
						node = grandParent;
					}
				}
				else{
					
					//When newly inserted node is at right
					if(node->key > parent->key){
						left_rotate(parent);
					}
				
					node->color = BLACK;
					grandParent->color = RED;
					right_rotate(grandParent);
					node = grandParent;	
				}
				
			}//When parent is right nodeof grand parent
			else{
				
				uncle = grandParent->left;

				if(uncle){
					//When uncle is red
					if(uncle->color == RED){
						parent->color = BLACK;
						uncle->color = BLACK;
						grandParent->color=RED;
						node = grandParent;
					}
					else{
						//When newly inserted node is at left
						if(node->key < parent->key){
							right_rotate(parent);
						}
					
						node->color = BLACK;
						grandParent->color = RED;
						left_rotate(grandParent);
						node = grandParent;	
					}
				}//When uncle is black
				else{
					//When newly inserted node is at left
					if(node->key < parent->key){
						right_rotate(parent);
					}
			
					node->color = BLACK;
					grandParent->color = RED;
					left_rotate(grandParent);
					node = grandParent;	
				}
			}
		}
	}

	//Finally change color of root to black
	this->root->color = BLACK;
}

template <class Key, class Value>
void RBTree<Key,Value> :: left_rotate(BinaryNode<Key,Value>* z){

	BinaryNode<Key,Value>* y = z->right;
	z->right = y->left;

	if(y->left)
		y->left->parent = z;

	y->parent = z->parent;

	if(!z->parent)
		this->root = y;
	else 
		if(z == z->parent->left)
			z->parent->left = y;
		else 
			z->parent->right = y;
	
	y->left = z;
	z->parent = y;
}


template <class Key, class Value>
void RBTree<Key,Value> :: right_rotate(BinaryNode<Key,Value>* z){

	BinaryNode<Key,Value>* y = z->left;
	z->left = y->right;

	if(y->right)
		y->right->parent = z;

	y->parent = z->parent;

	if(!z->parent)
		this->root = y;
	else 
		if(z == z->parent->right)
			z->parent->right = y;
		else 
			z->parent->left = y;
	
	y->right = z;
	z->parent = y;
}


template <class Key, class Value>
int RBTree<Key,Value> :: blackHeight(){

	return blackHeight(this->root);

}

template <class Key, class Value>
int RBTree<Key,Value> :: blackHeight(BinaryNode<Key,Value>* rt){

	if (rt == NULL)   
           return 1;

    if(rt->color == BLACK)
    	return 1 + blackHeight(rt->left);

    return blackHeight(rt->left);
}

template<class Key, class Value>
void RBTree<Key, Value>::remove(const Key& key){

	BinaryNode<Key,Value>* node = this->getNode(key);

	if(!node)
		return;

	if(!node->left && !node->right){
		BinaryNode<Key,Value>* parent = node->parent;
		BSTree<Key,Value> :: remove(key);
		deleteRBFixup(parent);
	}
	else{
		BSTree<Key,Value> :: remove(key);
	
		deleteRBFixup(node);
	}
}

template <class Key, class Value>
void RBTree<Key,Value> :: deleteRBFixup(BinaryNode<Key,Value>* rt){

	if(rt){
		BinaryNode<Key, Value>  *sibling, *parent = rt->parent;
		while(rt){

			if(rt != this->root){
				parent = rt->parent;
			}

			if(!rt->parent)
				break;
 
			if(rt == this->root){
				break;
			}
			else 
				if(rt->color != BLACK)
					break;

			if(rt->key < rt->parent->key){
				
				sibling = rt->parent->right;
				
				if(sibling->color == RED){
					sibling->color = BLACK;
					rt->parent->color = RED;
					left_rotate(rt->parent);
					sibling = rt->parent->right;
				}

				if(!sibling->right && !sibling->left){
					sibling->color = RED;
					rt = rt->parent;	
				}
				else{
					if(sibling->left->color == BLACK && sibling->right->color == BLACK){
						sibling->color = RED;
						rt = rt->parent;
					}
					else{
						 if(!sibling->right){

							sibling->left->color = BLACK;
							sibling->color = RED;
							right_rotate(sibling);
							
							sibling = rt->parent->right;
						}
						else{
							if(sibling->right->color == BLACK){
								sibling->left->color = BLACK;
								sibling->color = RED;
								right_rotate(sibling);
					
								sibling = rt->parent->right;
							}
	
							sibling->color = rt->parent->color;
							rt->parent->color = BLACK;
							sibling->right->color = BLACK;
							left_rotate(rt->parent);

							rt=this->root;
						}
					}
				}
			}
			else{
				sibling = rt->parent->left;
			
				if(sibling->color == RED){

					sibling->color = BLACK;
					rt->parent->color = RED;
					right_rotate(rt->parent);
					sibling = rt->parent->left;
				}
				
				if(!sibling->right && !sibling->left){
					sibling->color=RED;
					rt = rt->parent;	
				}
				else{
					if(sibling->right->color == BLACK && sibling->left->color == BLACK){
						sibling->color = RED;
						rt = rt->parent;
					}
					else{ 
						if(!sibling->left){
							sibling->right->color = BLACK;
							sibling->color = RED;
							left_rotate(sibling);
							
							sibling = rt->parent->left;
						}
						else{
							if(sibling->left->color == BLACK){

								sibling->right->color = BLACK;
								sibling->color = RED;
								left_rotate(sibling);
								sibling = rt->parent->left;
							}
						
							sibling->color = rt->parent->color;
							rt->parent->color = BLACK;
							sibling->left->color = BLACK;
							right_rotate(rt->parent);
							rt = this->root;
						}
					}
				}	
			}
		}

		rt->color = BLACK;
	}
}


template <class Key, class Value>
int RBTree<Key,Value> :: color(Key key){

	if(this->has(key)){
		
		BinaryNode<Key,Value>*  node = this->getNode(key);

		if(node->color == RED){
			
			std::cout << "RED";
		}
		else{
			std::cout << "BLACK";
		}
	}
}


//end of namespace
}



#endif /* ifndef RBTree_HPP_ */