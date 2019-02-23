#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define m 998244353

typedef long long ll;

ll pwrmod(ll a, ll b){
    ll res = 1; 
    assert(b>=0);
    for(; b>0 ; b>>=1){
        if(b&1) res = ((res%m)*(a%m))%m;
        a = ((a%m)*(a%m))%m;
    }
    return res%m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<ll> a(n, 0);
    vector<ll> last(n, 0);
    map<ll,ll> mp;
    ll ans = 1;
    for(int i=0 ; i<n ; i++) cin>>a[i];

    for(int i=n-1 ; i>=0 ; i--){
        if(!mp.count(a[i])){
            mp[a[i]] = i;
        }
        last[i] = mp[a[i]];
    }   
    ll cmax = -1;
    for(int i=0 ; i<n-1 ; i++){
        cmax = max(cmax, last[i]);
        if(cmax == i){
            ans = ((ans%m)*2)%m;
        }
    }

    cout<<ans<<endl;

    return 0;
}