#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll phi(ll n){
    ll res = n;
    for(int i=2 ; i*i <= n ; i++){
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
            }
            res -= res / i;
        }
    }
    if(n > 1){
        res -= res/n;
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
        ll n;
        cin>>n;
        cout<<phi(n)<<endl;
    }

    return 0;
}