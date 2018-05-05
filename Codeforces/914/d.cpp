#include <bits/stdc++.h>
#include <numeric>

#define ll long long
using namespace std;

int arr[500000];
set<int> tree[500000];

void fillprime(set<int>& a,int n){
    for(int i=2 ; i<=sqrt(n) ; i++){
        while(n%i != 0){
            a.insert(i);
            n/=i;
        }
    }
}

void build(int node,int start,int end){
	if(start == end){
        fillprime(tree[node],arr[start]);
	}else{
		int mid = start + (end - start)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
        int minf = end-start;
        set_union(tree[2*node].begin(),tree[2*node].end(),tree[2*node+1].begin(),tree[2*node+1].end(),tree[node].begin());
	}
}

void update(int node,int start,int end,int idx,int val){
	if(start == end){
        fillprime(tree[node],val);
		arr[idx] = val;
	}else{
		int mid = start + (end-start)/2;
		if(idx >= start and idx <= mid){
			update(2*node,start,mid,idx,val);
		}else{
			update(2*node+1,mid+1,end,idx,val);
		}
		set_union(tree[2*node].begin(),tree[2*node].end(),tree[2*node+1].begin(),tree[2*node+1].end(),tree[node].begin());
	}
}

set<int> query(int node,int start,int end,int l,int r){
	if(start > r or end < l){
		return ;
	}
	if(l<= start and r >= end){
		return tree[node];
	}
	int mid = start + (end-start)/2;
	return __gcd(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
}



int main(){

	int n;
	cin>>n;

	for(int i=1 ; i<=n ; i++){
		cin>>arr[i];
	}

	build(1,1,n);
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int l,r,x;
            cin>>l>>r>>x;
            int rgcd = query(1,1,n,l,r);
            if(rgcd == x) cout<<"YES"<<endl;    
        }else{
            int idx,y;
            cin>>idx>>y;
            update(1,1,n,idx,y);
        }
    }    
}