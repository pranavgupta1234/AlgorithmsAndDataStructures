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


bool isSumTree(node* root){

	if(root == NULL){
		return true;
	}else{
		bool a,b,c;
		if(root -> left == NULL and root -> right ==  NULL){
			a = true;
		}else{
			a = root -> data == (sumUtil(root -> left) + sumUtil(root -> right));
		}

		b = isSumTree(root -> left);
		c = isSumTree(root -> right);

		return (a and b and c);
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