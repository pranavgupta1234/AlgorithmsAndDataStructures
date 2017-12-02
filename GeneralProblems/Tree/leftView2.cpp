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

void leftViewUtil(node* root,int level,int& maxLevel){

	if(root == NULL){
		return;
	}

	if(maxLevel < level){
		cout<<root -> data<<" ";
		maxLevel = level;
	}

	leftViewUtil(root -> left,level+1,maxLevel);
	leftViewUtil(root -> right,level+1,maxLevel);
}

void leftView(node* root){
	int maxLevel = 0;
	leftViewUtil(root,1,maxLevel);
}

int main(){	
	node* root = newNode(1);	
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
	root -> right -> right -> right = newNode(9);
	root -> right -> right -> left = newNode(8);
	leftView(root);
	cout<<endl;

	return 0;
}