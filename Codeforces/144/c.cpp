#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp[30][100100];
int pat[30][100100];
int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s,t;
    cin>>s>>t;
    n = s.length(), m = t.length();

    if(m > n) cout<<0<<endl,exit(0);
    
    dp[s[0]-'a'][1]++;
    for(int i=0 ; i<26 ; i++) {
        for(int j=2 ; j<=n ; j++){
            if(s[j-1]-'a' == i) dp[i][j] = dp[i][j-1]+1;
            else dp[i][j] = dp[i][j-1];
        }
    }

    pat[t[0]-'a'][1]++;
    for(int i=0 ; i<26 ; i++) {
        for(int j=2 ; j<=m ; j++){
            if(t[j-1]-'a' == i) pat[i][j] = pat[i][j-1]+1;
            else pat[i][j] = pat[i][j-1];
        }
    }
    
    for(int i=0 ; i<26 ; i++){
        for(int j=0 ; j<=n ; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0 ; i<26 ; i++){
        for(int j=0 ; j<=m ; j++){
            cout<<pat[i][j]<<" ";
        }
        cout<<endl;
    }
    
   int ans = 0;
   for(int i=1 ; i<=n-m ; i++){
       int k = i;
       bool f = true;
       for(int j=0 ; j<26 ; j++){
           if(dp[j][i+m] - dp[j][i-1] != pat[j][m-1]){
               f = false;
               break;
           } 
       }
       if(f) ans++;
   }
    cout<<ans<<endl;
    return 0;
}