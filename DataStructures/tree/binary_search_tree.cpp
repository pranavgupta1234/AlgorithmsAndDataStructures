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

int main(){
	
	node* root = NULL;
	root = insert(root,3);
	root = insert(root,4);
	root = insert(root,6);
	root = insert(root,89);
	root = insert(root,45);

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