#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mod 1000000007

ll pwrmod(ll a,ll b){
    ll res = 1;
    for(; b ; b>>=1){
        if(b&1) res = res*a%mod;
        a = ((a%mod)*(a%mod))%mod;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        ll an = pwrmod(a,n);
        ll bn = pwrmod(b,n);
        ll anbn = (an+bn)%mod;
        cout<<__gcd(anbn,abs(a-b)%mod)<<endl;
    }

    return 0;
}