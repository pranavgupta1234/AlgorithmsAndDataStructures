#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double dbl;
typedef vector<int> vi;
typedef vector<ll> vii;
typedef pair<int,int> pii;
typedef tree<ll, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
const ll mod=1000000007;

ll gcd(ll a,ll b) { return  b ? gcd(b,a%b) : a ; }
ll pwrmod(ll a,ll b) {
    ll res=1;
    a %= mod;
    assert(b>=0);
    for( ; b ; b>>=1) {
        if(b&1) res = res*a%mod;
        a = a*a%mod;
    }
    return res;
}
ll pwr(ll a,ll b){
    ll res=1;
    assert(b >= 0);
    for( ; b ; b>>=1) {
        if(b&1) res = res*a;
        a = a*a;
    }
    return res;
}
ll eea(ll a,ll b,ll &x,ll &y) {
    if(a == 0) {
        x=0 ; y=1 ;
        return b;
    }
    ll x1, y1;
    ll d = eea(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return d;
}

ll bsearch(vector<ll>& a,ll val,ll l,ll h){
    while(l<=h){
        ll mid = l + (h-l)/2;
        if(a[mid] == val) return mid;
        else if(a[mid]<val) l = mid+1;
        else h = mid-1;
    }
    return -1;
}

vector<ll> g[400100];
ll n,q;
vector<ll> e,e2;
int h[400100];
int dp[400100];

void dfs(int u,int p){
    e.push_back(u);
    dp[u] = 1;
    ll num = 0;
    for(auto i : g[u]){
        if(i != p) {
            dfs(i,u);
            e.push_back(u);
            num += dp[i]; 
        }
    }
    dp[u] += num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for(int i=2 ; i<=n ; i++){
        ll p;
        cin>>p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    for(int i=1 ; i<=n ; i++) sort(g[i].begin(),g[i].end());
    dfs(1,1);
    for(int i=0 ; i<e.size() ; i++){
        if(h[e[i]] != 1) {
            e2.push_back(e[i]);
            h[e[i]] = 1;
        } 
    }
    while(q--){
        ll u,k;
        cin>>u>>k;
        if(k > dp[u]) {
            cout<<-1<<endl;
            continue;
        }
        ll p = bsearch(e2,u,0,e2.size()-1);
        cout<<e2[p+k-1]<<endl;
    }
    return 0;
} 
