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

void levelOrderR2L(node* root,int h){

	if(root == NULL){
		return;
	}
	if(h == 1){
		cout<<root -> data<<" ";
	}else{
		levelOrderR2L(root -> right,h-1);
		levelOrderR2L(root -> left,h-1);
	}
}

void levelOrderL2R(node* root,int h){
	if(root == NULL){
		return;
	}
	if(h == 1){
		cout<<root -> data<<" ";
	}else{
		levelOrderL2R(root -> left,h-1);
		levelOrderL2R(root -> right,h-1);
	}
}

int height(node* root){
	if(root == NULL){
		return 0;
	}
	return 1 + max(height(root -> left),height(root -> right));
}

void iterateHeight(node* root){
	int h = height(root);

	for(int i=1 ; i<= h ; i++){
		levelOrderL2R(root,i);
	}
}

int main(){
	
	node* root = newNode(1);	
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
	root -> right -> right -> right = newNode(9);
	root -> right -> right -> left = newNode(8);

	iterateHeight(root);
	cout<<endl;

	return 0;
}