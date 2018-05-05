#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        ll dp[n+1][n+1];
        for(int i=0 ; i<=n ; i++) dp[0][i] = 0;
        for(int i=0 ; i<=n ; i++) dp[i][0] = 1;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                dp[i][j] = (dp[i-1][j] + i*dp[i-1][j-1]%mod)%mod; 
            }
        }
        ll c = 0;
        for(int i=0 ; i<=n ; i++){
            if(dp[n][i] % p != 0) c++;
        }
        cout<<c<<endl;
    }
    return 0;
}