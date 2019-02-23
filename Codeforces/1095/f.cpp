#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back 

typedef long long ll;

vector<ll> par(200100, 0);
vector<ll> sz(200100, 1);

ll find(ll a){
    return (a == par[a] ? a : par[a] = find(par[a]));
}

void do_union(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(sz[a] <= sz[b]){
            swap(a, b);
        }
        sz[a] += sz[b];
        par[b] = a;
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n, m;
    cin>>n>>m;

    vector< pair<ll, pair<ll,ll> > > g;
    vector<pair<ll,ll> > cost(n, {0, 0});

    for(int i=0 ; i<=n ; i++) par[i] = i;

    for(int i=0 ; i<n ; i++){
        cin>>cost[i].F;
        cost[i].S = i+1;
    }

    for(int i=0 ; i<m ; i++){
        ll s, d, w;
        cin>>s>>d>>w;
        g.push_back({w, {s, d}});
    }

    sort(cost.begin(), cost.end());

    for(int i=1 ; i<n ; i++){
        g.push_back({cost[0].F + cost[i].F, {cost[0].S, cost[i].S}});
    }

    sort(g.begin(), g.end(), [](const pair<ll,pair<ll,ll> >& a, const pair<ll,pair<ll,ll> >& b) -> bool {
        return a.F < b.F;
    });

    ll c = 0;
    int e = 0;

    for(int i=0 ; i<g.size() ; i++){
        ll s,d,w;
        s = g[i].S.F;
        d = g[i].S.S;
        w = g[i].F;
        s = find(s);
        d = find(d);

        if(s != d){
            do_union(s, d);
            c += w;
            e++;
        }

        if(e == n-1){
            break;
        }
    }

    cout<<c<<endl;

    return 0; 
}