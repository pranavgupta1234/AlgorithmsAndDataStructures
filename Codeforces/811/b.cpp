#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n,m;
int arr[10040];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1 ; i<=n ; i++){
		cin>>arr[i];
	}	

	for(int i=0 ; i<m ; i++){
		int s,e,x;
		int less = 0;
		cin>>s>>e>>x;
		for(int i=s ; i<=e ; i++) if(arr[i] < arr[x]) less++;
		if(x == s + less) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

	return 0;
}
