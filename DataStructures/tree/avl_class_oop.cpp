#include <iostream>
using namespace std;

class AVL;

class node{

//as data fields of node class are private so making node as friend of AVL we can allow to access all fields of node  	
friend AVL;

private:

	int data;
	node* left;
	node* right;
	int height;

public:

	node();

};

class AVL{

private:

	node* root;

protected:

	node* insert_helper(node* root,int data);

	void pre_order_helper(node* root);

	void in_order_hepler(node* root);
	
	void post_order_helper(node* root);

	node* leftRotation(node* root);

	node* rightRotation(node* root);

	int getHeight(node* n);

	int getBalance(node* n);

	node* newNode(int data);

	node* deleter(node* root,int data);

	node* inorder_successor(node* root);

	 
public:

	AVL();

	void insert(int data);
	
	void remove(int data);

	void in_order();

	void pre_order();

	void post_order();	

};

int main(){

	AVL a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);

	a.pre_order();

	a.remove(4);


	return 0;
}

node :: node(){

	data = 0;
	left = NULL;
	right = NULL;	

}

node* AVL :: newNode(int data){
	
	node* newNodeOnHeap = new node();
	newNodeOnHeap -> data = data;
	newNodeOnHeap -> left = NULL;
	newNodeOnHeap -> right = NULL;

	return newNodeOnHeap;
}

AVL :: AVL(){
	root = NULL;
}

void AVL :: insert(int data){
	root = insert_helper(root,data);
}

node* AVL :: insert_helper(node* root,int data){

	if(root == NULL){
		return newNode(data);
	}

	if(root -> data > data){
		root -> left = insert_helper(root -> left,data);
	}else if(root -> data < data){
		root -> right = insert_helper(root -> right,data);
	}else{
		return root;
	}

	root -> height = 1+ max(getHeight(root -> left),getHeight(root -> right));				

	int bal = getBalance(root);													// imbalancing occurs around root (if occurs)

	if(bal > 1){

		//left left case
		if(getBalance(root->left) >= 0){
			return rightRotation(root);
		}
		//left right case
		else{
			root -> left = leftRotation(root -> left);
			return rightRotation(root);
		}
	}

	if(bal < -1){

		//right right case
		if(getBalance(root->right) <= 0){
			return leftRotation(root);
		}
		//right left case
		else{
			root -> right = rightRotation(root -> right);
			return leftRotation(root);
		}
	}

	return root;
}

void AVL :: pre_order(){
	pre_order_helper(root);
	cout<<endl;
}

void AVL :: post_order(){
	post_order_helper(root);
	cout<<endl;
}

void AVL :: in_order(){
	in_order_hepler(root);
	cout<<endl;
}

void AVL :: in_order_hepler(node* root){
	if(root != NULL){
		in_order_hepler(root -> left);
		cout<<root->data<<" ";
		in_order_hepler(root -> right);
	}
}

void AVL :: pre_order_helper(node* root){
	if(root != NULL){
		cout<<root->data<<" ";
		pre_order_helper(root -> left);
		pre_order_helper(root -> right);
	}
}

void AVL :: post_order_helper(node* root){
	if(root != NULL){
		post_order_helper(root -> left);
		post_order_helper(root -> right);
		cout<<root->data<<" ";
	}
}


node* AVL :: rightRotation(node* root){


	node* x = root -> left;
	node* y = x -> right;

	//Rotation
	x -> right = root;
	root -> left = y;


	x -> height = 1 + max(getHeight(x -> left),getHeight(x -> right));
	root -> height = 1 + max(getHeight(root -> left),getHeight(root -> right)); 

	return x;

}

node* AVL :: leftRotation(node* root){

	node* y = root -> right;
	node* x = y -> left;

	//Rotation 
	y -> left = root;
	root -> right = x;

	y -> height = 1 + max(getHeight(y -> left),getHeight(y -> right));
	root -> height = 1 + max(getHeight(root -> left),getHeight(root -> right)); 

	return y;

}

int AVL :: getBalance(node* n){
	return (getHeight(n -> left) - getHeight(n -> right));
}

int AVL :: getHeight(node* n){
	if(n!=NULL){
		return n -> height;		
	}

	return 0;
}

void AVL :: remove(int data){

	root = deleter(root,data);

}

node* AVL :: deleter(node* root,int data){

	if(root == NULL){
		return root;
	}

	if(root -> data > data){
		root -> left = deleter(root -> left,data);
	}else if(root -> data < data){
		root -> right = deleter(root -> right,data);
	}else{

		if( root -> left == NULL){
			node* temp = root -> right;
			delete root;
			return temp;
		}

		if(root -> right == NULL){
			node* temp = root -> left;
			delete root;
			return temp;
		}

		node* inorder_suc = inorder_successor(root -> right);

		root -> data = inorder_suc -> data;

		root -> right = deleter(root -> right,inorder_suc -> data); 
		
	}

	pre_order();

	if(root == NULL){
		return root;
	}

	root -> height = 1 + max(getHeight(root -> left),getHeight(root -> right));

	int bal = getBalance(root);

	if(bal > 1){

		//left left case
		if(data < root -> left -> data){
			return rightRotation(root);
		}
		//left right
		else{
			root -> left = leftRotation(root -> left);
			return rightRotation(root);
		}
	}

	if(bal < -1){

		//right right case
		if(data > root -> right -> data){
			return leftRotation(root);
		}
		//right left case
		else{
			root -> right = rightRotation(root -> right);
			return leftRotation(root);
		}
	}

	return root;

}

node* AVL :: inorder_successor(node* root){

	node* suc = root;

	while(suc -> left != NULL){
		suc = suc -> left;
	}

	return suc;
}