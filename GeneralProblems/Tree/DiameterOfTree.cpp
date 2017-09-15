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
// O(n^2)
int heightUnOptimized(node* root){
	if(root == NULL){
		return 0;
	}else{
		return 1 + max(heightUnOptimized(root -> left),heightUnOptimized(root ->right));
	}
}

int diameterUnOptimized(node* root,int& maxel){

	if(root == NULL){
		return 0;
	}else{

		int lheight = heightUnOptimized(root -> left);
		int rheight = heightUnOptimized(root -> right);

		maxel = max(maxel,1+lheight+rheight);

		return maxel;
	}
}
//O(n)
//we can pass a  variable by reference and get the max value of 1 + lheight + rheight in the same recursion
int heightOptimized(node* root,int& ans){
	if(root == NULL){
		return 0;
	}else{

		int lheight = heightOptimized(root -> left,ans);
		int rheight = heightOptimized(root ->right,ans);

		ans = max(ans,1+lheight+rheight);
		//cout<<ans<<endl;

		//but since still its a height function so we have to return this but here we utilized the recursion to get diameter
		return 1 + max(lheight,rheight);	
	}
}

int diameterOptimized(node* root){

	if(root == NULL){
		return 0;
	}else{

		int ans = -1;
		int height = heightOptimized(root,ans);
		cout<<height<<endl;
		return ans;
	}
}


int main(){

	int ans = -1;

	node* root = newNode(1);

	root -> left = newNode(2);
	root -> right = newNode(3);

	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);	

	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);	

	root -> right -> right -> right = newNode(89);	

	root -> right -> right -> right -> right= newNode(37);	

	cout<<diameterOptimized(root)<<endl;

	return 0;
}