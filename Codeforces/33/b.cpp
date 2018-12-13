#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll g[30][30];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string src,dest;
    cin>>src>>dest;  
    cin>>n;
    for(int i=0 ; i<26 ; i++){
        for(int j=0 ; j<26 ; j++){
            if(i!=j) g[i][j] = INT_MAX;
        }
    }
    for(int i=0 ; i<n ; i++){
        char s,d;
        ll w;
        cin>>s>>d>>w;
        g[s-'a'][d-'a'] = min(g[s-'a'][d-'a'],w);
    }
    if(src.length() != dest.length()) cout<<-1<<endl,exit(0);
    for(int k=0 ; k<26 ; k++){
        for(int i=0 ; i<26 ; i++){
            for(int j=0 ; j<26 ; j++){
                if(g[i][k] + g[k][j] < g[i][j]){
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    ll cost = 0;
    string ans;
    for(int i=0 ; i<src.length() ; i++){
        if(src[i] == dest[i]){
            ans += src[i];
            continue;
        }else{
            ll mn = INT_MAX;
            char v;
            for(char x='a' ; x<='z' ; x++){
                if(g[src[i]-'a'][x-'a'] + g[dest[i]-'a'][x-'a'] < mn){
                    mn = g[src[i]-'a'][x-'a'] + g[dest[i]-'a'][x-'a'];
                    v = x;
                }
            }
            cost += mn;
            ans += v;
        } 
    }
    if(cost >= INT_MAX) cout<<-1<<endl,exit(0);
    cout<<cost<<endl;;
    cout<<ans<<endl;
    return 0;
}