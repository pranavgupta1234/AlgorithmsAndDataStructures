#include <bits/stdc++.h>

using namespace std;
set<string> s;
string all;
int t;
map<string,int> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>all;
    s.insert("Danil"),s.insert("Olya"),s.insert("Slava"),s.insert("Ann"),s.insert("Nikita");
    for(auto it = s.begin() ; it !=s.end() ; it++){
        size_t nPos = all.find(*it,0);
        while(nPos != string::npos){
            m[*it]++;
            nPos = all.find(*it,nPos+1);
        }   
    }
    if(m.empty() or m.size() > 1) cout<<"NO"<<endl,exit(0);
    for(auto it=m.begin() ; it != m.end() ; it++) if(it -> second > 1) cout<<"NO"<<endl,exit(0);
    cout<<"YES"<<endl;
    return 0;
}