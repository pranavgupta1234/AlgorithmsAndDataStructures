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
#define maxn 15000000

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

ll bsearch(ll a[],ll val,ll l,ll h){
    while(l<=h){
        ll mid = l + (h-l)/2;
        if(a[mid] == val) return mid;
        else if(a[mid]<val) l = mid+1;
        else h = mid-1;
    }
    return -1;
}

vector<ll> spf;

void sieve(){
    spf.assign(15000000,0);
    for(int i=2 ; i<=maxn ; i++) spf[i] = i;
    for(int i=2 ; i<=maxn ; i+=2) spf[i] = 2;
    for(int i=3 ; i*i<= maxn ; i++){
        if(spf[i] == i){
            for(int j=i*i ; j<=maxn ; j+=i) {
                if(spf[j] == j) spf[j] = i;  
            }
        }
    } 
}

vector<ll> getfactorization(ll x){
    vector<ll> fact;
    while(x != 1){
        fact.push_back(spf[x]);
        x = x/spf[x];
    }
    return fact;
}

ll mat[2100][2100];
bool vis[2100][2100];
ll total;

ll bfs(int i,int j){
    queue<pair<int,int> > q;
    q.push({i,j});
    vis[i][j] = true;
    ll sum = mat[i][j];
    int si = i,sj = j,ei,ej;
    while(!q.empty()){
        pair<int,int> x = q.front();
        q.pop();

        int vi = x.first;
        int vj = x.second;

        if(vi -1 >= 0 and sum + mat[vi-1][vj] <= total and !vis[vi-1][vj]){
            vis[vi-1][vj] = true;
            q.push({vi-1, vj});
            sum += mat[vi-1][vj];
        }

        if(vi -1 >= 0 and sum + mat[vi-1][vj] <= total and !vis[vi-1][vj]){
            vis[vi-1][vj] = true;
            q.push({vi-1, vj});
            sum += mat[vi-1][vj];
        }

        if(vi -1 >= 0 and sum + mat[vi-1][vj] <= total and !vis[vi-1][vj]){
            vis[vi-1][vj] = true;
            q.push({vi-1, vj});
            sum += mat[vi-1][vj];
        }

        if(vi -1 >= 0 and sum + mat[vi-1][vj] <= total and !vis[vi-1][vj]){
            vis[vi-1][vj] = true;
            q.push({vi-1, vj});
            sum += mat[vi-1][vj];
        }


    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n,m;
    cin>>n>>m;

    vector<ll> a(n,0);
    vector<ll> b(m,0);
    vector<pair<ll,pair<ll,ll> > > v;  
    for(int i=0 ; i<n ; i++) cin>>a[i]; 
    for(int j=0 ; j<m ; j++) cin>>b[j];
    cin>>total;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            v.push_back({a[i]*b[j], {i, j}});
        }
    }

    sort(v.begin(),v.end());
    int c = 0;
    
    if(v[0].first > total) cout<<0<<endl,exit(0);
    int sum = 0;
    vector<bool> vis(n*m+1, false);
    
    for(int i=0 ; i<v.size() ; i++){
        if(sum < total){
            
        }
    }

    return 0;
} 
