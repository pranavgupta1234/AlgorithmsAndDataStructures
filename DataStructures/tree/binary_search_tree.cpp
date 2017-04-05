#include <iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* newNode(int);
node* insert(node*,int);
void inorder(node* root);
bool search(node* root,int val);
node* deleteNode(node* root,int val);

int main(){
	
	node* root = NULL;
	root = insert(root,89);
	root = insert(root,45);
	root = insert(root,3);
	root = insert(root,4);
	root = insert(root,6);

	inorder(root);

	root = deleteNode(root,89);

	inorder(root);
	return 0;
}

node* newNode(int val){

	node* newTempNode = new node();
	newTempNode -> data = val;
	newTempNode -> right = NULL;
	newTempNode -> left = NULL;

	return newTempNode;
}

node* insert(node* root,int val){

	if(root==NULL){
		return newNode(val);
	}

	if(root->data>val){
		root -> left = insert(root->left,val);
	}else{
		root -> right = insert(root->right,val);
	}

	return root;
}

void inorder(node* root){

	if(root != NULL){
       inorder(root->left);
       cout<<root->data<<endl;
       inorder(root->right);
    }
}

bool search(node* root,int val){

	if(root!=NULL){
		if(root -> data == val){
			return true;
		}

		if(root -> data > val){
			return search(root->left,val);
		}else{
			return search(root->right,val);
		}
	}

	return false;

}

node* InorderSuccessor(node* root){

	node* current = root;

	while(current -> right != NULL){
		current = current -> right;
	}

	return current;
}

node* deleteNode(node* root,int val){
	
	if(root == NULL){
		return root;
	}	

	if(root -> data > val){
		root -> left = deleteNode(root -> left,val);
	}else if(root -> data < val){
		root -> right = deleteNode(root -> right,val);
	}else{

		if(root -> left == NULL){
			node* temp_right = root -> right;
			delete root;
			return temp_right; 
		}

		if(root -> right == NULL){
			node* temp_left = root -> left;
			delete root;
			return temp_left;
		}

		node* inorder_successor = InorderSuccessor(root);

		root -> data = inorder_successor->data;

		root -> right = deleteNode(root -> right, inorder_successor -> data);

	}

	return root;

}