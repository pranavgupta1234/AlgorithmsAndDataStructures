#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lis(vector<ll>& a,ll n){
    vector<ll> dp(n+1,1);
    for(int i=2 ; i<=n ; i++){
        for(int j=1 ; j<i ; j++){
            if(a[j] < a[i]) dp[i] = max(dp[i],1+dp[j]);
        }
    }
    ll mx = 0;
    for(int i=1 ; i<=n ; i++) mx = max(mx,dp[i]);
    return mx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> a(n+1,0);
        for(int i=1 ; i<=n ; i++) cin>>a[i];
        cout<<lis(a,n);
        cout<<endl;
    }
    return 0;
}