#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;

    int h[26] = {0};
    for(int i=0 ; i<n ; i++) h[str[i]-'A']++;
    for(int i=0 ; i<k ; i++) if(h[i]==0) cout<<0<<endl,exit(0);
    
    int mn = 1000000000;
    for(int i=0 ; i<k ; i++) {
        mn = min(mn,h[i]);
    }   
    
    cout<<k*mn<<endl;
    return 0;
}