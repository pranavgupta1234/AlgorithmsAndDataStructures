#include <bits/stdc++.h>

#define ll long long
#define dll long double

using namespace std;

ll n,m;
map<string,string> ipton;
vector<pair<string,string>> comm;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1 ; i<=n ; i++){
        string name,ip;
        cin>>name>>ip;
        ipton[ip] = name;
    }
    for(int i=1 ; i<=m ; i++){
        string c,ip;
        cin>>c>>ip;
        comm.push_back(make_pair(c,ip));
    }

    for(auto it = comm.begin() ; it!=comm.end() ; it++){
        string f,s;
        f = (*it).first;
        s = (*it).second;
        s.pop_back();
        cout<<f<<" "<<s+";"<<" #"<<ipton[s]<<endl;
    }

    return 0;
}