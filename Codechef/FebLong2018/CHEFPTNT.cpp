#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,x,k;
        int o=0,e=0;
        string s;
        cin>>n>>m>>x>>k;
        cin>>s;
        for(int i=0 ; i<s.length() ; i++) if(s[i] == 'E') e++; else o++;
        for(int i=1 ; i<=m ; i++){
            if(i&1) if(o > 0) n-=( o < x ? o : x),o-=( o < x ? o : x);
            if(!(i&1)) if(e > 0) n-=( e < x ? e : x),e-=( e < x ? e : x);    
        }
        if(n<=0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}