#include <iostream>
#include <climits>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* newNode(int data){
	node* spawn = new node();
	spawn -> data = data;
	spawn -> left = NULL;
	spawn -> right = NULL;
	return spawn;
}

int maxDiffUtil(node* root,int& maxdiff){

	if(root == NULL){
		return INT_MAX;
	}

	if(root -> left == NULL and root -> right == NULL){
		return root -> data;
	}
	
	int val = min(maxDiffUtil(root -> left,maxdiff),maxDiffUtil(root -> right,maxdiff));

	maxdiff = max(maxdiff,root -> data - val);

	return min(root -> data,val);

}

int maxDiff(node* root){

	int maxdiff = INT_MIN;

	maxDiffUtil(root,maxdiff);

	return maxdiff;
}

int main(){
	

	node* root = newNode(8);
    root->left = newNode(3);
 
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

	cout<<maxDiff(root);

	cout<<endl;

	return 0;
}