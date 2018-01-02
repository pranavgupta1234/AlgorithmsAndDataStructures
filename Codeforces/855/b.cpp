#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll arr[100005];
ll dp[100005][3];

int main(){
	ios_base::sync_with_stdio(false);
	ll n,p,q,r;
	cin>>n>>p>>q>>r;

	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}

	dp[0][0] = p*arr[0];
	for(int i=1 ; i<n ; i++){
		dp[i][0] = max(dp[i-1][0],p*arr[i]);
	}

	dp[0][1] = dp[0][0] + q*arr[0];
	for(int i=1 ; i<n ; i++){
		dp[i][1] = max(dp[i-1][1],dp[i][0] + q*arr[i]);
	}

	dp[0][2] = dp[0][1] + r*arr[0];
	for(int i=1 ; i<n ; i++){
		dp[i][2] = max(dp[i-1][2],dp[i][1] + r*arr[i]);
	}

	cout<<dp[n-1][2]<<endl;

	return 0;
}