#include <iostream>
using namespace std;

class AVL;

class node{

//as data fields of node class are private so making it AVL as friend of node we can allow to access all fields of node  	
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

	node* remove_helper(node* root,int data);

	void pre_order_helper(node* root);

	void in_order_hepler(node* root);
	
	void post_order_helper(node* root);

	node* leftRotation(node* root);

	node* rightRotation(node* root);

	int getHeight(node* n);

	int getBalance(node* n);

	node* newNode(int data);

	 
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

	a.in_order();



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

	return n;
}

void AVL :: remove(int data){

}

node* AVL :: remove_helper(node* root,int data){

}

void AVL :: pre_order(){
	pre_order_helper(root);
}

void AVL :: post_order(){
	post_order_helper(root);
}

void AVL :: in_order(){
	in_order_hepler(root);
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
	return n -> height;
}