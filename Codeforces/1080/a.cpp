#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    cout<<(ll)(ceil(2.0*n/k) + ceil(5.0*n/k) + ceil(8.0*n/k))<<endl;

    return 0;
}