#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        map<char,int> m;
        map<char,vector<int> > loc;
        vector<int> o;
        char oddchar;
        ll odd = 0;
        loc.clear(),m.clear(),o.clear();
        for(int i=0 ; i<s.length() ; i++) m[s[i]]++,loc[s[i]].push_back(i+1);
        for(auto it = m.begin() ; it != m.end() ; it++) if(it -> second & 1) odd++,oddchar = it -> first;
        for(int i=0 ; i<s.length() ; i++) if(s[i] == oddchar) o.push_back(i+1);
        if(odd > 1) cout<<-1<<endl;
        else{
            for(auto it = m.begin() ; it != m.end() ; it++){
                if(it -> first != oddchar){
                    for(int i=0 ; i<loc[it -> first].size()/2 ; i++) cout<<loc[it->first][i]<<" ";
                }
            }
            for(int i=0 ; i<o.size() ; i++) cout<<o[i]<<" ";
            for(auto it = m.rbegin() ; it != m.rend() ; it++){
                if(it -> first != oddchar){
                    for(int i=loc[it -> first].size()/2 ; i<loc[it -> first].size() ; i++) cout<<loc[it -> first][i]<<" ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}