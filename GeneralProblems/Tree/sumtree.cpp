#include <iostream>

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

int sumUtil(node* root){
	if(root == NULL){
		return 0;
	}else{
		return sumUtil(root->left) + sumUtil(root -> right) + root -> data;
	}
}

//O(n2) approach
bool isSumTree(node* root){
	if(root == NULL or (root -> left == NULL and root -> right == NULL)){
		return true;
	}else{
		return (root -> data == (sumUtil(root -> left) + sumUtil(root -> right)) and isSumTree(root -> left) and isSumTree(root -> right));
	}
}

int main(){
	node* root = NULL;
	root = newNode(26);
	root -> left = newNode(10);
	root -> right = newNode(3);

	root -> left -> left = newNode(4);
	root -> left -> right = newNode(6);

	root -> right -> left = newNode(1);
	root -> right -> right = newNode(2);

	//cout<<sumUtil(root)<<endl;
	cout<<(isSumTree(root) ? "Yes a Sum Tree" : "Not a Sum Tree");

	cout<<endl;
	return 0;
}