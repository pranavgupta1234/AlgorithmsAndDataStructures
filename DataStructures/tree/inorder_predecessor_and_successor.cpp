#include <iostream>
using namespace std;

struct node{

	int data;
	node* left;
	node* right;
};

node* newNode(int);
node* insert(node*,int);
void inorder(node*);
void SucPredKey(node*,node*&,node*&,int);

int main(){

	node* root = NULL;
	node* pre = NULL;
	node* suc = NULL;

	root = insert(root,50);
	root = insert(root,30);
	root = insert(root,20);
	root = insert(root,40);
	root = insert(root,70);
	root = insert(root,60);
	root = insert(root,80);


	inorder(root);
	cout<<endl;

	SucPredKey(root,pre,suc,50);



	if(suc!=NULL){
		cout<<"Successor is "<<suc -> data<<endl;
	}else{
		cout<<"No Successor"<<endl;
	}


	if(pre != NULL){
		cout<<"Predecessor is "<<pre -> data<<endl;
	}else{
		cout<<"No Predecessor"<<endl;
	}

	return 0;
}

node* newNode(int val){

	node* newTempNode = new node();
	newTempNode -> data = val;
	newTempNode -> left = NULL;
	newTempNode -> right = NULL;

	return newTempNode;
}

node* insert(node* root,int val){

	if(root==NULL){
		return newNode(val);
	}

	if(root->data>val){
		root -> left = insert(root->left,val);
	}else{
		root -> right = insert(root->right,val);
	}

	return root;
}

void inorder(node* root){

	if(root != NULL){
		inorder(root -> left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void SucPredKey(node* root,node*& pre,node*& suc,int val){

	if(root == NULL){
		return; 
	}

	if(root -> data == val){

		if(root -> left != NULL){

			node* temp_right = root -> left;

			while(temp_right -> right!= NULL){
				temp_right = temp_right -> right;
			}

			pre = temp_right;
		}

		if(root -> right != NULL){

			node* temp_left = root -> right;

			while(temp_left -> left != NULL){
				temp_left = temp_left -> left;
			}

			suc = temp_left;	
		}
		return;

	}else if(root -> data > val){
		suc = root;
		SucPredKey(root -> left,pre,suc,val);
	}else if(root -> data < val){
		pre = root;
		SucPredKey(root -> right,pre,suc,val);
	}

}
