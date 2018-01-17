#include <bits/stdc++.h>

#define ll long long 
#define inf 1000000007;

using namespace std;

int comp(ll a,ll b)	{return a > b;}	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		bool f = true;
		int n;
		cin>>n;
		vector<vector<int> > seq(n+1,vector<int>(n,0));
		for(int i=0 ; i<n  ; i++)	for(int j=0 ; j<n ; j++)	cin>>seq[i][j];	
		for(int i=0 ; i<n  ; i++)	sort(seq[i].begin(),seq[i].end()); 	
		int r = n-2;
		ll sum = seq[n-1][n-1];
		ll el = seq[n-1][n-1];
		while(r >= 0){
			vector<int> :: iterator it = lower_bound(seq[r].begin(),seq[r].end(),el);
 			int pos = it - seq[r].begin() - 1;
 			if(it != seq[r].begin()){
 				sum += seq[r][pos];
 				el = seq[r][pos];
 				r--;
 			}else{
 				f = false;
 				break;		
 			}
		}

		if(f) cout<<sum<<endl;
		else cout<<"-1"<<endl;
	}

	return 0;
}