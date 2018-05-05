#include <bits/stdc++.h>

#define ll long long
#define dll long double

using namespace std;


ll* arr;
ll* treem;
ll* treex;

void buildm(int node,int start,int end){
	if(start == end){
		treem[node] = arr[start];
	}else{
		int mid = start + (end - start)/2;
		buildm(2*node,start,mid);
		buildm(2*node+1,mid+1,end);
        treem[node] = min(treem[2*node],treem[2*node+1]);
	}
}

ll querym(int node,int start,int end,int l,int r){
	if(start > r or end < l){
		return INT_MAX;
	}
	if(l<= start and r >= end){
		return treem[node];
	}
	int mid = start + (end-start)/2;
	return min(querym(2*node,start,mid,l,r),querym(2*node+1,mid+1,end,l,r));
}

void buildx(int node,int start,int end){
	if(start == end){
		treex[node] = arr[start];
	}else{
		int mid = start + (end - start)/2;
		buildx(2*node,start,mid);
		buildx(2*node+1,mid+1,end);
        treex[node] = treex[2*node] ^ treex[2*node+1];
	}
}

ll queryx(int node,int start,int end,int l,int r){
	if(start > r or end < l){
		return 0;
	}
	if(l<= start and r >= end){
		return treex[node];
	}
	int mid = start + (end-start)/2;
	return (queryx(2*node,start,mid,l,r) ^ queryx(2*node+1,mid+1,end,l,r));
}


int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
	cin>>n>>k;
	int ts = pow(2,ceil(log2(n))+1);	
	arr = new ll[n+1];	
	treem = new ll[ts];			
    treex = new ll[ts];													// 1 based indexing
	memset(arr,0,sizeof(arr[0])*(n+1));
	memset(treem,0,sizeof(treem[0])*ts);
    memset(treex,0,sizeof(treex[0])*ts);
	for(int i=1 ; i<=n ; i++)	cin>>arr[i];
	buildm(1,1,n);
    buildx(1,1,n);
    vector<ll> vals;
    for(int i=1 ; i<=n ; i++){
        for(int j=i ; j<=n ; j++){
            ll valm = querym(1,1,n,i,j);
            ll valx = queryx(1,1,n,i,j);  
            //cout<<i<<" "<<j<<" "<<valm<<" "<<valx<<endl;          
            vals.push_back(valm*valx);
        }
    }
    //for(int i=0 ; i<vals.size() ; i++) cout<<vals[i]<<" ";
    //cout<<endl;
    sort(vals.begin(),vals.end());
    cout<<vals[k-1]<<endl;
    return 0;
}