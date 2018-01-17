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

bool allpre(ll num){
	for(int i=0 ; i<n ; i++){
		while(num % primes[i] == 0){
			num /= primes[i];
		}
	}

	if(num == 1)	return true;
	else return false;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>primes[i];
	}
	cin>>k;
	ll it = 1;
	for(ll i=2 ; i>0 ; i++){	
		if(allpre(i)){
			it++;
		}
		if(it == k){
			ans = i;
			break;
		}
	}

	cout<<ans<<endl;
	return 0;
}