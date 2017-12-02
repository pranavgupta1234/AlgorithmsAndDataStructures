#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct node{
	int data;
	node* left;
	node* right;
}node;

node* newNode(int data){
	node* newnode = new node();
	newnode -> data = data;
	newnode -> left = NULL;
	newnode -> right = NULL;
	return newnode;
}

bool checkBST(node* root,node* l = NULL,node* r = NULL){
	if(root == NULL){
		return true;
	}
	if(l != NULL and root -> data < l -> data){
		return false;
	}
	if(r != NULL and root -> data > r -> data){
		return false;
	}

	return checkBST(root -> left,l,root) and checkBST(root -> right,root,r);

}

void checkBSTByInorderUtil(node* root,int* arr,int& index){
	if(root != NULL){
		checkBSTByInorderUtil(root -> left,arr,index);
		arr[index] = root -> data;
		index++;
		checkBSTByInorderUtil(root -> right,arr,index);
	}
}

int countNodes(node* root){
	if(root == NULL){
		return 0;
	}
	return 1 + countNodes(root -> left) + countNodes(root -> right);
}

bool checkBSTByInorder(node* root){
	int n = countNodes(root);
	int* arr = new int[n];
	memset(arr,0,n*sizeof(arr[0]));
	int index = 0;
	checkBSTByInorderUtil(root,arr,index);
	int check = arr[0];
	for(int i=1 ; i<n; i++){
		if(arr[i] < check){
			return false;
		}else{
			check = arr[i];
		}
	}
	return true;
}


int lowestVal(node* root){
	while(root -> left != NULL){
		root = root -> left;
	}
	return root -> data;
}

int main(){

	node* root = newNode(10);	
	root -> left = newNode(6);
	root -> right = newNode(15);
	root -> left -> left = newNode(1);
	root -> left -> right = newNode(8);
	root -> right -> left = newNode(12);
	root -> right -> right = newNode(24);

	cout<<checkBSTByInorder(root)<<endl;
	return 0;
}