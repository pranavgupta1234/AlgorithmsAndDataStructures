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

bool checkEqualTree(node* root1,node* root2){

	if(root1 == NULL and root2 == NULL){
		return true;
	}

	if(root1 != NULL and root2 != NULL){

		return (
			root1 -> data == root2 -> data and
			checkEqualTree(root1 -> left,root2 -> left) and
			checkEqualTree(root1 -> right,root2 -> right)
			);
	}

	return false;
}

int main(){
	
	node* root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);

	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);

	node* root1 = newNode(1);
	root1 -> left = newNode(2);
	root1 -> right = newNode(3);

	root1 -> left -> left = newNode(4);
	root1 -> left -> right = newNode(5);		

	if(checkEqualTree(root,root1)){
		cout<<"Trees are equal"<<endl;
	}else{
		cout<<"Trees are diff"<<endl;
	}

	return 0;
}