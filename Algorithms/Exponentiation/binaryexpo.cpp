#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll binpow (ll a,ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		ll b = binpow (a, n/2);
		return b * b;
	}
}

ll power(ll x,ll y,ll mod){
    ll res = 1;
    x = x % mod;
    while(y>0){
        if(y&1) res = ((res%mod)*(x%mod))%mod;
        y >>= 1;
        x = ((x%mod)*(x%mod))%mod;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<binpow(2,100)<<endl;
    cout<<power(1248555,100000,10000000009)<<endl;
    return 0;
}