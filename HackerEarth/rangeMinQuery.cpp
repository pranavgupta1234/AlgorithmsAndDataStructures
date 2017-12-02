#include <bits/stdc++.h>

using namespace std;

void buildUtil(vector<int>& tree,vector<int>& arr,int node,int start,int end){
    if(start == end){
        tree[node] = arr[start];
    }else{
        int mid = (start+end)/2;
        buildUtil(tree,arr,2*node,start,mid);
        buildUtil(tree,arr,2*node+1,mid+1,end);
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}

void build(vector<int>& tree,vector<int>& arr){
    buildUtil(tree,arr,1,0,arr.size()-1);
}

int queryUtil(vector<int>& tree,int node,int start,int end,int l,int r){
    if(l > end or r < start){
        return INT_MAX;
    }
    if(l <= start and r >= end){
        return tree[node];
    }
    int mid = (start+end)/2;
    return min(queryUtil(tree,2*node,start,mid,l,r),queryUtil(tree,2*node+1,mid+1,end,l,r));
}

int query(vector<int>& tree,int arrsize,int l,int r){
    return queryUtil(tree,1,0,arrsize-1,l-1,r-1);
}

void updateUtil(vector<int>& tree,vector<int>& arr,int node,int start,int end,int idx,int val){
    if(start == end){
        arr[idx] = val;
        tree[node] = val;
    }else{
        int mid = (start+end)/2;
        if(start <= idx and idx<= mid){
            updateUtil(tree,arr,2*node,start,mid,idx,val);
        }else{
            updateUtil(tree,arr,2*node+1,mid+1,end,idx,val);
        }
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}

void update(vector<int>& tree,vector<int>& arr,int idx,int val){
    updateUtil(tree,arr,1,0,arr.size()-1,idx-1,val);    
}

int main(){
    int n,q;
    cin>>n>>q;
    int maxsize;
    vector<int> arr(n,0);
    maxsize = 2*(int)pow(2,ceil(log2(n)));
    vector<int> tree(maxsize,0);
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    build(tree,arr);
    for(int i=0 ; i<q ; i++){
        char type;
        int par1,par2;
        cin>>type>>par1>>par2;
        if(type == 'u'){
            //make update
            update(tree,arr,par1,par2);
        }else{
            //make query
            cout<<query(tree,arr.size(),par1,par2)<<endl;
        }
    }
    return 0;
}