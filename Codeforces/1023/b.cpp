#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    if(k <= n){
        cout<<(k-1)/2<<endl;
    }else{
        if(k > 2*n) cout<<0<<endl;
        else cout<<n-(k/2+1)+1<<endl;
    }
    return 0;
}