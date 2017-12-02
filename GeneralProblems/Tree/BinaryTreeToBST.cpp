#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node{
	int data;
	node* left;
	node* right;
}node;

node* newNode(int data){
	node* newnd = new node();
	newnd -> data = data;
	newnd -> left = NULL;
	newnd -> right = NULL;
	return newnd;
}

void storeInorder(node* root,int arr[],int& i){
	if(root != NULL){
		storeInorder(root -> left,arr,i);
		arr[i] = root -> data;
		(i)++;
		storeInorder(root -> right,arr,i);
	}
}

int countNodes(node* root){
	if(root == NULL){
		return 0;
	}
	return 1 + countNodes(root -> left) + countNodes(root -> right);
}

void arrayToBST(node* root,int* arr,int& i){
	if(root != NULL){
		arrayToBST(root -> left,arr,i);
		root -> data = arr[i];
		i++;
		arrayToBST(root -> right,arr,i);
	}
}

void binaryToBST(node* root){

	if(root == NULL){
		return;
	}

	int n = countNodes(root);

	int *arr = new int[n];

	for(int i=0 ; i<n ; i++){
		arr[i] = 0;
	}
	int i = 0;
	storeInorder(root,arr,i);
	i=0;
	sort(arr,arr+n);
	arrayToBST(root,arr,i);
}

void inorder(node* root){
	if(root != NULL){
		inorder(root -> left);
		cout<<root -> data<<" ";
		inorder(root -> right);
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

	binaryToBST(root);

	inorder(root);

	cout<<endl;

	return 0;
}