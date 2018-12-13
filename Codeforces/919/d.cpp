#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> g[300100];
bool vis[300100];
char v[300100];

void dfs(ll u){
    vis[u] = true;
    for(auto i : g[u]){
        if(!vis[i]) {
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    for(int i=1 ; i<=n ; i++) cin>>v[i];
    for(int i=0 ; i<m ; i++){
        int s,d;
        cin>>s>>d;
        g[s].push_back(d);
    }

    








    return 0;
}