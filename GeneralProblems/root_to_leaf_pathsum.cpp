#include <iostream>
#include <vector>

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

bool hasPathSum(node* root,int sum){

	if(root == NULL){
		return (sum == 0);
	}else{

		bool ans = false;

		int subSum = sum - root -> data;

		if(subSum == 0 and root -> left == NULL and root -> right == NULL){
			return true;
		}

		if(root -> left){
			ans = ans or hasPathSum(root-> left,subSum);
		}
		if(root -> right){
			ans = ans or hasPathSum(root -> right,subSum);
		}

		return ans;
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

	cout<<(hasPathSum(root,8) ? "YES" : "NO")<<endl;

	return 0;
}