#include <iostream>
#include <vector>

using namespace std;

void buildUtil(vector<int>&tree,vector<int>& arr,int node,int start,int end){
	if(start == end){
		tree[node] = arr[start];
	}else{
		int mid = (start+end)/2;
		buildUtil(tree,arr,2*node,start,mid);
		buildUtil(tree,arr,2*node,mid+1,end);
		tree[node] = 
	}
}

int main(){
	
	return 0;
}