#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define N 210500

typedef long long ll;

ll n, m;
ll a[N], u[N], v[N], w[N], lvl[N], par[N], sz[N], f[N];
pair<ll,ll> dp[N][32];
vector<pair<ll,ll> > mst[N];

bool comp(ll a, ll b){
    return w[a] < w[b];
}

ll rep(ll a){
    if(a == par[a]) return a;
    else return par[a] = rep(par[a]);
}

void do_union(ll a, ll b){
    a = rep(a);
    b = rep(b);
    if(a != b){
        if(sz[a] < sz[b]){
            swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
    }
}

void dfs(ll u, ll p=0, ll l=0){
    lvl[u] = l;
    for(auto i : mst[u]){
        if(i.F == p) continue;
        dp[i.F][0].F = u;
        dp[i.F][0].S = i.S;
        dfs(i.F, u, l+1);
    }
}

void pre(){
	for(ll j=1;j<22;j++){
		for(ll i=1;i<=n;i++){
			dp[i][j].F=dp[dp[i][j-1].F][j-1].F;
			dp[i][j].S=max(dp[i][j-1].S,dp[dp[i][j-1].F][j-1].S);
		}
	}
}

void pre(){
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=21 ; j++){
            dp[i][j].F = dp[dp[i][j-1].F][j-1].F;
            dp[i][j].S = max(dp[i][j-1].S, dp[dp[i][j-1].F][j-1].S);
        }
    }
}

ll getlcawt(ll u, ll v){
    if(lvl[u] < lvl[v]) swap(u, v);
    ll ans = 0;
    for(int i=21 ; i>=0 ; i--){
        if(lvl[u] - (1<<i) >= lvl[v]){
            ans = max(ans, dp[u][i].S);
            u = dp[u][i].F;
        }
    }
    if(u == v) return ans;
    for(int i=21 ; i>=0 ; i--){
        if(dp[u][i].F != dp[v][i].F){
            ans = max(ans, dp[u][i].S);
            ans = max(ans, dp[v][i].S);
            u = dp[u][i].F;
            v = dp[v][i].F;
        }
    }
    ans = max(ans, dp[u][0].S);
    ans = max(ans, dp[v][0].S);

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i=1 ; i<=m ; i++){
        cin >> u[i] >> v[i] >> w[i];
        a[i] = i;
    }

    sort(a+1, a+m+1, comp); 
    
    for(int i=1 ; i<=n ; i++) par[i] = i, sz[i] = 1;

    for(int i=1 ; i<=m ; i++){
        ll id = a[i];
        ll s = u[id];
        ll d = v[id];
        ll wt = w[id];
        ll r1 = rep(s);
        ll r2 = rep(d);
        if(r1 != r2){
            do_union(r1, r2);
            f[id] = 1;
            mst[s].push_back({d, wt});
            mst[d].push_back({s, wt});
        }
    }

    dfs(1);
    pre();
    ll ans = 0;
    for(int i=1 ; i<=m ; i++){
        if(f[i]) continue;
        else{
            if(w[i] == getlcawt(u[i], v[i])) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}