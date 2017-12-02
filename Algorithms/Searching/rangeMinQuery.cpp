#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

//requires O(n) space
void buildTreeUtil(vector<int>& tree,vector<int>& arr,int node,int start,int end){
	if(start == end){
		tree[node] = arr[start];
	}else{
		int mid = (start+end)/2;
		buildTreeUtil(tree,arr,2*node,start,mid);
		buildTreeUtil(tree,arr,2*node+1,mid+1,end);
		tree[node] = min(tree[2*node],tree[2*node+1]);
	}
}

//O(logn) time
void updateUtil(vector<int>& tree,vector<int>& arr,int node,int start,int end,int idx,int val){
	if(start == end){
		arr[idx] = val;
		tree[node] = val;
	}else{
		int mid = (start+end)/2;
		if(start <= idx and idx <= mid){
			updateUtil(tree,arr,2*node,start,mid,idx,val);
		}else{
			updateUtil(tree,arr,2*node+1,mid+1,end,idx,val);
		}
		tree[node] = min(tree[2*node],tree[2*node+1]);
	}
}

//O(logn) time to query
int queryUtil(vector<int>& tree,int node,int start,int end,int l,int r){
	if(r < start or l > end){
		return INT_MAX;
	}
	if(l <= start and r >= end){
		return tree[node];
	}
	int mid = (start + end)/2;
	return min(queryUtil(tree,2*node,start,mid,l,r),queryUtil(tree,2*node+1,mid+1,end,l,r));
}

int query(vector<int>& tree,int arrsize,int l,int r){
	return queryUtil(tree,1,0,arrsize-1,l-1,r-1);
}

void update(vector<int>& tree,vector<int>& arr,int idx,int val){
	updateUtil(tree,arr,1,0,arr.size()-1,idx-1,val);
}

void buildTree(vector<int>& tree,vector<int>& arr){
	buildTreeUtil(tree,arr,1,0,arr.size()-1);
}

int main(){

	vector<int> arr = { 2, 4, 6, 3, 11};
	int maxTreeSize = 2*(int)pow(2,ceil(log2(arr.size())));			//actual space needed will include -1 but take all to use 1 based indexing
	vector<int> tree(maxTreeSize,0);
	buildTree(tree,arr);
	cout<<query(tree,arr.size(),1,5)<<endl;
	update(tree,arr,3,1);
	cout<<query(tree,arr.size(),1,5)<<endl;
	return 0;
}