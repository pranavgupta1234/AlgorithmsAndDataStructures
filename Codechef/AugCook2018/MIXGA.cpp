#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> a(n,0);
        ll sum = 0;
        for(int i=0 ; i<n ; i++){
            cin>>a[i];
            if(i&1) {
                if(sum < 0){
                    sum += a[i];
                } else{
                    sum -= a[i];
                }
            }else{
                if(sum < 0){
                    sum -= a[i];
                }else{
                    sum += a[i];
                }
            }
        }
        if(abs(sum) >= k) {
            cout<<1<<endl;
        }  else{
            cout<<2<<endl;
        }
    }
    return 0;
}