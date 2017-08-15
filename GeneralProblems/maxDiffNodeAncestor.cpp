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

int maxDiff(node* root,int diff){

	if(root == NULL){
		return root -> data - diff;
	}else{


	}


}

int main(){
	




	return 0;
}