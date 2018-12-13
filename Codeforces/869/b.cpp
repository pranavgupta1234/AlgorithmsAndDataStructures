#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fact(ll n){
    if(n==0) return 1;
    else return n*fact(n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll a,b;
    cin>>a>>b;
    if(b-a >= 5) cout<<0<<endl;
    else {
        ll ans = 1;
        for(ll i=a+1 ; i<=b ; i++){
            ans = (ans*i)%10;
        }
        cout<<ans<<endl;
    }
    return 0;
}