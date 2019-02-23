#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define N 200100

typedef long long ll;

vector<ll> g[N];
vector<ll> s(N, 0);
vector<ll> lvl(N, 0);
ll ans = 0;
bool poss = true;

void dfs(int u, int p, int gp){
    lvl[u] = lvl[p] + 1; 
    ll mn = INT_MAX;
    if(lvl[u] >= 2){
        if(s[u] < s[gp]){
            poss = false;
            return ;
        }
    }
    for(auto i : g[u]){
        if(i == p) continue;
        dfs(i, u, p);
        if(lvl[u]&1)  mn = min(mn, s[i]);
    }
    if(s[u] == -1) {
        s[u] = (mn == INT_MAX ? 0 : mn); 
    }
}

void calc(int u, int p){
    if(s[u] != 0) ans += s[u] - s[p];
    for(auto i : g[u]){
        if(i == p) continue;
        calc(i, u);
    }
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=2 ; i<=n ; i++) {
        int p;
        cin>>p;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    for(int i=1 ; i<=n ; i++){
        cin>>s[i];
    } 

    lvl[0] = -1;
    dfs(1, 0, 0);

    //for(int i=1 ; i<=n ; i++) cout<<s[i]<<" ";
    //exit(0);

    calc(1, 0);

    if(!poss) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}