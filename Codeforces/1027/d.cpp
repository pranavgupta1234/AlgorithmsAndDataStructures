#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
vector<int> g[200100];
ll c[200100];
ll par[200100];
ll color[200100];
bool vis[200100];
ll ans;

ll cycle(int s,int e){
    ll mn = INT_MAX;
    if(e == s) return c[e];
    mn = min(mn,c[e]);
    mn = min(mn,c[s]);    
    while(e != s){
        mn = min(mn,c[e]);
        e = par[e];
    }
    return mn;
}

void dfs(int s){
    color[s] = 1;
    vis[s] = true;
    for(auto i : g[s]){
        if(color[i] == 0){
            par[i] = s;
            dfs(i);
        }else if(color[i] == 1){
            ans += cycle(i,s);
        }
    }
    color[s] = 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>c[i];
    for(int i=1 ; i<=n ; i++){
        int d;
        cin>>d;
        g[i].push_back(d);
    }
    for(int i=1 ; i<=n ; i++) vis[i] = false;
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    cout<<ans<<endl;

    return 0;
}