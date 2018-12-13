#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin>>n>>m;
    vector<ll> a(n,0);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    ll pref = 0;
    ll p = 0;
    for(int i=0 ; i<n ; i++){
        pref += a[i];
        ll curr = pref/m;
        cout<<curr-p<<" ";
        p = curr;
    }
    cout<<endl;
    return 0;
}