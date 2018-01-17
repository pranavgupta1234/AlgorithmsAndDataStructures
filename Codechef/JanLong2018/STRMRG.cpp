#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string str1,str2;
        cin>>str1>>str2;
        str1 = " "+str1,str2 = " "+str2;
        int dp[n+1][m+1];
        for(int i=0 ; i<=n ; i++)   for(int j=0 ; j<=m ; j++)   dp[i][j] = 0;
        dp[1][0] = 1, dp[0][1] = 1;
        for(int i=2 ; i<=n ; i++) dp[i][0] = dp[i-1][0] + (str1[i] != str1[i-1] ? 1 : 0);
        for(int i=2 ; i<=m ; i++) dp[0][i] = dp[0][i-1] + (str2[i] != str2[i-1] ? 1 : 0); 
        int hash[26];
        for(int i=0 ; i<26 ; i++) hash[i] = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(str1[i] != str2[j] and hash[str1[i]-'a']==0)  dp[i][j] = dp[i-1][j]+1; 
                else dp[i][j] = dp[i-1][j],hash[str1[i]-'a']++;
            }
            hash[str1[i]-'a'] = 0;
        }    
        for(int i=0 ; i<=n ; i++){
            for(int j=0 ; j<=m ; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<dp[n][m]<<endl;
    }   
    return 0;
}
