#include <iostream>
#include <vector>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
	node* rightLeft;
};

node* newNode(int data){

	node* newnode = new node();
	newnode -> data = data;
	newnode -> left = NULL;
	newnode -> right = NULL;
	newnode -> rightLeft = NULL;

	return newnode;
}

int main(){
	




	return 0;
}