#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin>>n;
    vector<ll> a(n,0);
    vector<ll> b(n,0);

    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int j=0 ; j<n ; j++) cin>>b[j];

    sort(a.begin(),a.end(),greater<ll>());
    sort(b.begin(),b.end(),greater<ll>());

    ll x=0,y=0;
    ll i=0, j=0;
    bool t = true;
    while(i < n and j < n){
        if(t){
            if(a[i] >= b[j]){
                x += a[i];
                i++;
            }else {
                j++;
            }
        }else{
            if(b[j] >= a[i]){
                y += b[j];
                j++;
            }else{
                i++;
            }
        }
        t = !t;
        //cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
        if(j == n){
            if(t) {
                for(int k=j ; k<n ; k+=2) x += a[k];
            }else{
                
            }
            break;
        }
        if(i == n){
            if(!t) y += b[j];
            j++;
        }
    }
    cout<<(x-y)<<endl;

    return 0;
}