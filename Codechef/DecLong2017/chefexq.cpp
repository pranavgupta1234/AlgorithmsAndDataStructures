#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>

#define range 1000007

using namespace std;


//requires O(n) space
void buildTreeUtil(int tree[],int arr[],int node,int start,int end,int* hashedK){
	if(start == end){
		tree[node] = arr[start];
	}else{
		int mid = (start+end)/2;
		buildTreeUtil(tree,arr,2*node,start,mid,hashedK);
		buildTreeUtil(tree,arr,2*node+1,mid+1,end,hashedK);
		tree[node] = tree[2*node]^tree[2*node+1];
	}
}

//O(logn) time
void updateUtil(int tree[],int arr[],int node,int start,int end,int idx,int val){
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
		tree[node] = tree[2*node]^tree[2*node+1];
	}
}

//O(logn) time to query
int queryUtil(int tree[],int node,int start,int end,int l,int r){
	if(r < start or l > end){
		return 0;
	}
	if(l <= start and r >= end){
		return tree[node];
	}
	int mid = (start + end)/2;
	return queryUtil(tree,2*node,start,mid,l,r)^queryUtil(tree,2*node+1,mid+1,end,l,r);
}

int query(int tree[],int arrsize,int l,int r){
	return queryUtil(tree,1,0,arrsize-1,l-1,r-1);
}

void update(int tree[],int arr[],int idx,int val,int size){
	updateUtil(tree,arr,1,0,size-1,idx-1,val);
}

void buildTree(int tree[],int arr[],int size,int* hashedK){
	buildTreeUtil(tree,arr,1,0,size-1,hashedK);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	int arr[n];
	int hashedK[range];
	memset(hashedK,0,sizeof(hashedK[0])*n);
	memset(arr,0,sizeof(arr[0])*n);
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}
	int maxTreeSize = 2*(int)pow(2,ceil(log2(n)));			//actual space needed will include -1 but take all to use 1 based indexing
	int tree[maxTreeSize];
	memset(tree,0,sizeof(tree[0])*n);
	buildTree(tree,arr,n,hashedK);
	for(int k=0 ; k<q ; k++){
		int type,i,x;
		cin>>type>>i>>x;
		if(type == 1){
			//update
			update(tree,arr,i,x,n);
		}else if(type == 2){
			//query
			int totalNum = 0;
			int val = query(tree,n,1,i);
			if(val == x){
				totalNum++;
			}

			for(int j=i; j>1 ; j--){
				if(arr[j-1] != 0){
					val = val^arr[j-1];
					if(val == x){
						totalNum++;
					}
				}else{
					totalNum++;
				}
			}
			cout<<totalNum<<endl;
		}
	}
	return 0;
}