#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define m 998244353

ll fact(ll n){
    ll res = 1;
    for(ll i=1 ; i<=n ; i++){
        res = ((res%m)*(i%m))%m; 
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin>>n;

    cout<<fact(n) + (n%m)*(fact(n-1)%m - 1)%m + ((n%m)*(fact(n-1)/2))%m<<endl;


    return 0;
}