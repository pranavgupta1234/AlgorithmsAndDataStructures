#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n,m;
ll a[55];
ll b[55];
ll mx;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    for(int i=1 ; i<=m ; i++) cin>>b[i];
    ll ans = LONG_LONG_MAX;
    int ex = 1;
    while(ex <= n){
        mx = -LONG_LONG_MIN;
        for(int i=1 ; i<=m ; i++){
            for(int j=1 ; j<=n ; j++){
                if(j != ex) mx = max(mx,a[j]*b[i]);
            }
        }
        ans = min(ans,mx);
        //cout<<ex<<" "<<mx<<endl;
        ex++;
    }   
    cout<<ans<<endl;
    return 0;
}