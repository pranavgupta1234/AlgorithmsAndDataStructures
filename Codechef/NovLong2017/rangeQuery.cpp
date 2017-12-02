#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <utility>

using namespace std;

void build(vector<pair<long long,long long> >& tree,int arr[],int node, int start, int end,int min_val,int max_val){
	if(start == end){
		tree[node].first = arr[start];
		if(arr[start] >= min_val and arr[start] <= max_val){
			tree[node].second++;
		}
	}
	else{
		int mid = (start + end) / 2;
		build(tree,arr,2*node, start, mid,min_val,max_val);
		build(tree,arr,2*node+1, mid+1, end,min_val,max_val);
		tree[node].first = max(tree[2*node].first,tree[2*node+1].first);
		if(tree[node].first <= max_val and tree[node].first >= min_val){
			tree[node].second++;
		}
		if(tree[2*node].first <= max_val and tree[2*node].first >= min_val){
			tree[node].second++;
		}
		if(tree[2*node+1].first <= max_val and tree[2*node+1].first >= min_val){
			tree[node].second++;
		}
	}
}

int query(vector<pair<long long,long long> >& tree,int node, int start, int end, int l, int r){
	if(r < start or end < l){
		return 0;
	}
	if(l <= start and end <= r){
		return tree[node].second;
	}
	int mid = (start + end) / 2;
	int p1 = query(tree,2*node, start, mid, l, r);
	int p2 = query(tree,2*node+1, mid+1, end, l, r);
	return p1+p2;
}

void update(vector<pair<long long,long long> >& tree,int arr[],int node, int start, int end, int idx, int val,int min_val,int max_val){
	if(start == end){
		arr[idx] = val;
		tree[node].first = val;
		if(val >= min_val and val <= max_val){
			tree[node].second++;
		}
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid){
			update(tree,arr,2*node, start, mid, idx, val,min_val,max_val);
		}
		else{
			update(tree,arr,2*node+1, mid+1, end, idx, val,min_val,max_val);
		}
		tree[node].first = max(tree[2*node].first,tree[2*node+1].first);
		if(tree[node].first <= max_val and tree[node].first >= min_val){
			tree[node].second++;
		}s
		if(tree[2*node].first <= max_val and tree[2*node].first >= min_val){
			tree[node].second++;
		}
		if(tree[2*node+1].first <= max_val and tree[2*node+1].first >= min_val){
			tree[node].second++;
		}
	}
}

int main(){
	
	int n,q,l,r;
	cin>>n>>q>>l>>r;
	int maxsize = (int)pow(2,ceil(log2(n))+1);
	int* arr = new int[n];
	memset(arr,0,sizeof(arr[0])*n);
	vector<pair<long long,long long> > tree(maxsize,make_pair(0,0));
	build(tree,arr,1,0,n-1,l,r);
	for(int i=0 ; i<tree.size() ; i++){
		cout<<tree[i].first<<" "<<tree[i].second<<endl;
	}
	while(q--){
		int type,start_idx,end_idx;
		cin>>type>>start_idx>>end_idx;
		if(type == 1){
			//make update
			update(tree,arr,1,0,n-1,start_idx-1,end_idx,l,r);
			for(int i=0 ; i<tree.size() ; i++){
				cout<<tree[i].first<<" "<<tree[i].second<<endl;
			}
		}else{
			//make query
			cout<<query(tree,1,0,n-1,start_idx-1,end_idx-1)<<endl;
		}
	}


	return 0;
}