#include <bits/stdc++.h>

#define m 1000000000000000000
#define ll long long

using namespace std;

int n;
ll k;
int primes[50];
ll maxpows[50];
ll ans;
vector<ll> nums;
ll mmpow; 


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>primes[i];
	}
	cin>>k;

	for(int i=0 ; i<n ; i++){
		int j = 0;
		while(pow(primes[i],j)<= m){
			j++;
		}
		maxpows[i] = j;
		mmpow = max(mmpow,j);
	}

	ll dp[mmpow+1][20][mmpow+1];

	for(int i=0 ; i<=mmpow ; i++){
		dp[i][0][i] = pow(primes[0],i);
	}

	for(int i=1 ; i<n ; i++){
		for(int j=0 ; j<maxpows[i] ; j++){
			for(int k = 0 ; k<maxpows[i-1] ; k++){
				ll temp = 
			}
		}
	}

	for(int )



	return 0;
}