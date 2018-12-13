#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,d;
    cin>>n>>d;

    vector<ll> a(n,0);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    ll cnt = 0;
    for(int i=0 ; i<n ; i++){
        auto p = upper_bound(a.begin(),a.end(),a[i]+d);
        ll pos = p - a.begin();
        ll poss = pos-i-1;
        cnt += poss*(poss-1)/2;
    }
    cout<<cnt<<endl;

    return 0;
}