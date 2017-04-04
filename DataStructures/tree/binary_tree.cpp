#include <iostream>
using namespace std;


struct node{
	int data;
	node* left;
	node* right;
};

node* newNode(int value){
	node* newTempNode = new node();
	newTempNode -> data = value;
	newTempNode -> left = NULL;
	newTempNode -> right = NULL;
}

int main(){

	node* tree;

	tree = newNode(4);

	tree -> left = newNode(1);
	tree -> right = newNode(2);

	cout<<tree->data<<endl<<tree->left->data<<endl<<tree->right->data<<endl;

	return 0;
}