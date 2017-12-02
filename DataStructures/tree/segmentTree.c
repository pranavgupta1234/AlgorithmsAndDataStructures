#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

//node corres to a node in tree(rep as array of size 2n) while start and end are index to original array
void build(int tree[],int arr[],int node, int start, int end){
    if(start == end){
        tree[node] = arr[start];
    }
    else{
        int mid = (start + end) / 2;
        build(tree,arr,2*node, start, mid);
        build(tree,arr,2*node+1, mid+1, end);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }
}

int query(int tree[],int node, int start, int end, int l, int r){
    if(r < start or end < l){
        return 0;
    }
    if(l <= start and end <= r){
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(tree,2*node, start, mid, l, r);
    int p2 = query(tree,2*node+1, mid+1, end, l, r);
    return max(p1,p2);
}

void update(int tree[],int arr[],int node, int start, int end, int idx, int val){
    if(start == end){
        arr[idx] = val;
        tree[node] = val;
    }
    else{
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid){
            update(tree,arr,2*node, start, mid, idx, val);
        }
        else{
            update(tree,arr,2*node+1, mid+1, end, idx, val);
        }
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
    int maxsize = 0;
    //remember that structure of segment tree normally isn't changed at runtime but updation can occur
    //for an array with n elements we have n leaves and n-1 internal nodes for tree hence overall 2n-1 elements
    //due to absence of some child nodes some values will be zero
    //All levels of the constructed segment tree will be completely filled except the last level.
    //Also, the tree will be a Full Binary Tree because we always divide segments in two halves at every level. Since the constructed tree is always full binary tree with n leaves, there will be n-1 internal nodes.
    //So total number of nodes will be 2*n – 1.
    //Height of the segment tree will be log2(n). Since the tree is represented using array and relation between parent and child indexes must be maintained, size of memory allocated for segment tree will be st3
    maxsize = (int)pow(2,ceil(log2(n))+1);
    int tree[maxsize];
    memset(tree,0,sizeof(tree[0])*(maxsize));
    build(tree,arr,1,0,n-1);
    cout<<query(tree,1,0,n-1,0,3)<<endl;
    update(tree,arr,1,0,n-1,3,9);
    cout<<query(tree,1,0,n-1,0,3);
}