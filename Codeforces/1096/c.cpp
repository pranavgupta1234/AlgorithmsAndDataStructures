#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;

    while(t--){
        ll x;
        cin>>x; 
        ll g = __gcd(180LL, x);
        ll n = 180LL/g;
        ll k = 1;
        if(g != x) k = x/g; 
        if(n >= 2*k) cout<<n<<endl;
        else cout<<2*n<<endl;
    }

    return 0;
}