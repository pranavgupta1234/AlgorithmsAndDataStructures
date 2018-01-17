#include <bits/stdc++.h>

using namespace std;

#define ll long long 

struct node{
	ll data;
	node* left;
	node* right;
};

int n;
node* root;
int a[100100];
unordered_map<ll,ll> parent;

node* newNode(int data){
	node* newnd = new node();
	newnd -> data = data;
	newnd -> left = NULL;
	newnd -> right = NULL;
	return newnd;
}

node* insert(node* root,int data){
	if(root == NULL){
		return newNode(data);
	}else{
		if(root -> data < data){
			root -> right = insert(root -> right,data);
			parent[root -> right -> data] = root -> data;
		}else{
			root -> left = insert(root -> left,data);
			parent[root -> left -> data] = root -> data;
		}
	}

	return root;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>a[i];
		root = insert(root,a[i]);
	}

	for(int i=1 ; i<n ; i++){
		cout<<parent[a[i]]<<" ";
	}

	cout<<endl;
	return 0;
}
