#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 200100

vector<ll> g[N];
vector<ll> col(N, -1);
vector<pair<ll,ll> > edges;
bool isb = true;
int n, m;

bool isbipartite(){
    queue<int> q;
    q.push(1);
    col[1] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto i : g[v]){
            if(col[i] == -1){
                col[i] = col[v] ^ 1;
                q.push(i);
            }else{
                isb = isb & (col[i] != col[v]);
            }
        }
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;

    //cleanup
    edges.clear();
    
    for(int i=1 ; i<=m ; i++){
        int s, d;
        cin>>s>>d;
        g[s].push_back(d);
        g[d].push_back(s);
        edges.push_back({s, d});
    }

    isbipartite();

    if(!isb){
        cout<<"NO"<<endl;
        exit(0);
    }

    string ans="";

    for(int i=0 ; i<edges.size() ; i++){
        if(col[edges[i].first] == 0){
            ans += "0";
        }else{
            ans += "1";
        }
    }
    
    cout<<"YES"<<endl;
    cout<<ans<<endl;

    return 0;
}