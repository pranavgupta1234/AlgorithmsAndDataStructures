#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    if(t.length()+1 < s.length()) cout<<"NO"<<endl,exit(0);
    if(s.find('*') == string::npos) {
        if(s != t) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }else{
        string p1,p2;
        int i=0; 
        while(s[i] != '*'){
            p1 += s[i];
            i++;
        }
        i++;
        while(i<n){
            p2 += s[i];
            i++;
        }
        
        for(int i=0 ; i<p1.length() ; i++){
            if(p1[i] != t[i]) cout<<"NO"<<endl,exit(0);
        }
        for(int i=0 ; i<p2.length() ; i++){
            if(p2[p2.length()-i-1] != t[m-i-1]) cout<<"NO"<<endl,exit(0);
        }
        cout<<"YES"<<endl;
    }


    return 0;
}