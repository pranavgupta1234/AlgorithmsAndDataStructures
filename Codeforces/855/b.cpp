#include <bits/stdc++.h>

#define ll long long

using namespace std;


int arr[100005];
ll dp[100005][3];

int main(){
	ios_base::sync_with_stdio(false);
	int n,p,q,r;
	cin>>n>>p>>q>>r;

	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}

	dp[0][0] = 1ll*p*a[0];
	for(int i=0 ; i<n ; i++){
		dp[i][0] = max(dp[i-1][0],p*a[i]);
	}

	dp[0][1] = 1ll*q*a[0];
	for(int i=0 ; i<n ; i++){
		dp[i][1] = max(dp[i-1][])
	}

	return 0;
}