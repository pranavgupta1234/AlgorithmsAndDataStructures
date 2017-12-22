#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

//for n we need 2n-1 space for euler path of tree
vector<int> E;														// +1 to maintain 1 based indexing
vector<int> dep;	
int* L;																// level
int* F;																// F[i] tells first occuring idx of i in E[i] 
int ptr;
int* tree;

void build(int node,int start,int end){
	if(start == end){
		tree[node] = E[start];
	}else{
		int mid = start + (end-start)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node] = min(tree[2*node],tree[2*node+1]);
	}
}

void update(int node,int start,int end,int idx,int val){
	if(start == end){
		E[idx] = val;
		tree[node] = val; 
	}else{
		int mid = start + (end-start)/2;
		if(start <= idx and idx <=mid){
			update(2*node,start,mid,idx,val);
		}else{
			update(2*node+1,mid+1,end,idx,val);
		}
		tree[node] = min(tree[2*node],tree[2*node+1]);
	} 
}

int query(int node,int start,int end,int l,int r){
	if(l > end or r < start){
		return INT_MAX;
	}
	if(l <= start and r >= end){
		return tree[node];
	} 

	int mid = start + (end-start)/2;

	return min(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
}

void dfs(vector<int> graph[],int curr,int prev,int depth){
	if(F[curr] == -1){
		F[curr] = ptr;
	}
	L[curr] = depth;
	E.push_back(curr);
	ptr++;				
	for(int i=0 ; i<graph[curr].size() ; i++){
		if(graph[curr][i] != prev){
			dfs(graph,graph[curr][i],curr,depth+1);
			E.push_back(curr);
			ptr++;
		}
	}
}

void deptharr(){
	for (int i=0 ; i<E.size() ; i++){
		dep.push_back(L[E[i]]);
	}
}

int lca(int u,int v){
	if(u == v){
		return u;
	}
	if(F[u] > F[v]){
		swap(F[u],F[v]);
	}

	return query(1,0,E.size()-1,F[u],F[v]);
}


//consider a rooted tree with n vertices(undirected) and so has n-1 edges and root is 1
int main(){

	int n;
	cin>>n;

	int parent[n+1];
	vector<int> graph[n+1];
	memset(parent,0,sizeof(parent[0])*(n+1));
	for(int i=2 ; i<=n ; i++){
		cin>>parent[i];											//tree[i] is parent of i
		graph[parent[i]].push_back(i);							//corres graph rep
		graph[i].push_back(parent[i]);
	}

	L = new int[2*n+1];
	F = new int[n+1];

	memset(L,0,sizeof(L[0])*(2*n+1));
	memset(F,-1,sizeof(F[0])*(n+1));

	//this segment creates all three required arrays
	ptr = 0;
	dfs(graph,1,0,0);	
	deptharr();

	int treesize = pow(2,ceil(log2(E.size()))+1);
	tree = new int[treesize];
	memset(tree,0,sizeof(tree[0])*treesize);
	for(int i=0 ; i<E.size() ; i++){
		cout<<E[i]<<" ";
	}
	cout<<endl;
	build(1,0,E.size()-1);

	int q;
	cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<lca(u,v)<<endl;
	}
	return 0;
}