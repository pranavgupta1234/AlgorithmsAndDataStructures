#include <iostream>
#include <vector>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* newNode(int data){
	
	node* newnode = new node();
	newnode -> data = data;
	newnode -> left = NULL;
	newnode -> right = NULL;

	return newnode;
}

void mirrorTree(node* root){

	if(root==NULL){
		return ;
	}

	mirrorTree(root -> left);
	mirrorTree(root -> right); 

	node* temp = root -> right;
	root -> right = root -> left;
	root -> left = temp;

}

void inorder(node* root){

	if(root == NULL){
		return;
	}
	inorder(root -> left);
	cout<<root -> data<<" ";
	inorder(root -> right);
}

int main(){
	
	node* root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> right -> right = newNode(5);

	inorder(root);

	cout<<endl;

	mirrorTree(root);

	inorder(root);

	cout<<endl;

	return 0;
}