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

void levelOrder(node* root,int h,int flag){

	if(root == NULL){
		return;
	}else if(h == 1){
		cout<<root -> data<<" ";
	}else{
		if(flag){
			levelOrder(root -> right,h-1,flag);
			levelOrder(root -> left,h-1,flag);
		}else{
			levelOrder(root -> left,h-1,flag);
			levelOrder(root -> right,h-1,flag);
		}
	}
}

int height(node* root){

	if(root == NULL){
		return 0;
	}else{
		return 1 + max(height(root -> left),height(root -> right));
	}
}


void iterateHeight(node* root){

	int h = height(root);
	int flag = 0;
	for(int i=1 ; i<= h ; i++){
		flag ? flag = 0 : flag = 1;
		levelOrder(root,i,flag);
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
	root -> right -> right -> left = newNode(8);
	root -> right -> right -> right = newNode(9);

	iterateHeight(root);
	cout<<endl;

	return 0;
}