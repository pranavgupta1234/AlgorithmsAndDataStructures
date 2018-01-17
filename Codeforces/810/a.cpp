#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n,k;
ll sum ;

int main(){
	cin>>n>>k;
	for(int i=0 ; i<n ; i++){
		int t;
		cin>>t;
		sum += t;
	}

	cout<<(n*(2*k-1) - 2*sum < 0 ? 0  : n*(2*k-1) - 2*sum )<<endl;

	return 0;
}