#include <bits/stdc++.h>

#define ll long long
#define ull long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n;
    ll hi[n];
    for(ll i=0 ; i<n ; i++)    cin>>hi[i];
    cin>>q;
    for(ll i=0; i<q ; i++){
        ll x,y;
        cin>>x>>y;
        for(ll i=0 ; i<n ; i++){
            if((i&x) == i)  hi[i] -= y;
        }   
        ll liv = 0;
        for(ll i=0 ; i<n ; i++) if(hi[i] > 0) liv++;
        cout<<liv<<endl;
    }

    return 0;    
}