#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//exponential solution
int lcs(string a,string b){
    if(a.length() == 0 or b.length() == 0) return 0;
    if(a[a.length()-1] == b[b.length()-1]){
        a.pop_back();
        b.pop_back();
        return 1 + lcs(a,b);
    }else{
        string a1 = a;
        string b1 = b;
        a1.pop_back();
        b1.pop_back();
        return max(lcs(a,b1),lcs(a1,b));
    }
}

//mn solution
int lcsDP(string a,string b){
    int n = a.length();
    int m = b.length();
    ll dp[n+1][m+1];
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=m ; j++){
            if(i == 0 or j == 0) dp[i][j] = 0;
            else if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str1,str2;
    cin>>str1>>str2;
    cout<<lcs(str1,str2);
    cout<<endl;
    cout<<lcsDP(str1,str2);
    cout<<endl;
    return 0;
}