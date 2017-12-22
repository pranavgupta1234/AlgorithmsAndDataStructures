#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int* arr;
int* tree;

void build(int node,int start,int end){
	if(start == end){
		tree[node] = arr[start];
	}else{
		int mid = start + (end - start)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

void update(int node,int start,int end,int idx,int val){
	if(start == end){
		tree[node] = val;
		arr[idx] = val;
	}else{
		int mid = start + (end-start)/2;
		if(idx >= start and idx <= mid){
			update(2*node,start,mid,idx,val);
		}else{
			update(2*node+1,mid+1,end,idx,val);
		}
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int query(int node,int start,int end,int l,int r){
	if(start > r or end < l){
		return 0;
	}
	if(l<= start and r >= end){
		return tree[node];
	}
	int mid = start + (end-start)/2;
	return query(2*node,start,mid,l,r) + query(2*node+1,mid+1,end,l,r);
}



int main(){

	int n;
	cin>>n;
	int ts = pow(2,ceil(log2(n))+1);
	
	arr = new int[n+1];	
	tree = new int[ts];													// 1 based indexing
	
	memset(arr,0,sizeof(arr[0])*(n+1));
	memset(tree,0,sizeof(tree[0])*ts);

	for(int i=1 ; i<=n ; i++){
		cin>>arr[i];
	}

	build(1,1,n);

	cout<<query(1,1,n,1,5)<<endl;

	update(1,1,n,3,100);

	cout<<query(1,1,n,1,5)<<endl;
}