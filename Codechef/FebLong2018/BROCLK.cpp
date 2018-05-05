#include <bits/stdc++.h>
#include <numeric>

#define ll long long
#define dll long double

using namespace std;

#define PI 3.141592653589793238462643L
#define mod 1000000007

ll gcd (ll a,ll b,ll& x,ll& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd (b%a, a, x1, y1);
	x = y1%mod - ((b / a)%mod * x1%mod)%mod;
	y = x1%mod;
	return d;
}

ll power(ll x,ll y,ll p){
    ll res = 1;      // Initialize result
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;  
    }
    return res;
}
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){ 
        ll l,d,t;
        cin>>l>>d>>t;      
        ll num,den;
        if(t==1) num = d,den = l;
        else if(t==2) num = 2*power(d,2,mod)-power(l,2,mod),den = power(l,2,mod);
        else num =  4*power(d,3,mod)-3*d*power(l,2,mod),den = power(l,3,mod);
        num = l*num%mod;
        ll gc = __gcd(num,den);
        num = num/gc,den = den/gc;
        ll r,y; 
        ll g = gcd(den,mod,r,y);
        cout<<((num*r)%mod + mod)%mod<<endl;    
    }
    return 0;
}