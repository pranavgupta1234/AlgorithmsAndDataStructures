#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[30][7100];

inline bool valid(int i,int j,int k){
    ll val = -1;
    ll f = 0;
    for(int c=0 ; c<26 ; c++){
        if(dp[c][j] - dp[c][i-1] > 0){
            if(val != -1 and val != dp[c][j] - dp[c][i-1]) return false;
            val = dp[c][j] - dp[c][i-1];
            f++;
        }   
    } 
    if(f < k) return false;
    else return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
        string str;
        ll k;
        cin>>str>>k;
        for(int i=0 ; i<26 ; i++) for(int j=0 ; j<=str.length() ; j++) dp[i][j] = 0;
        dp[str[0]-'a'][1] = 1;
        for(char i='a' ; i<='z' ; i++){
            for(int j=0 ; j<str.length() ; j++){
                if(str[j] == i) dp[i-'a'][j+1] = dp[i-'a'][j] + 1;
                else dp[i-'a'][j+1] = dp[i-'a'][j];
            }
        }
        ll cnt = 0;
        for(int i=1 ; i<=str.length() ; i++){
            for(int j=i+k-1 ; j<=str.length() ; j++){
                if(valid(i,j,k)) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}