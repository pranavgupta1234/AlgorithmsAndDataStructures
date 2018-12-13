#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> a(n,0);
        for(int i=0 ; i<n ; i++) cin>>a[i];
        ll g = 1;
        for(int i=0 ; i<n-1 ; i++)  g = __gcd(a[i],a[i+1]);
        bool f = false;
        for(int i=2 ; i<=sqrt(g) ; i++){
            if(g % i == 0){
                if(i > k or g/i > k) f = true;
            } 
        }
        if(f) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}