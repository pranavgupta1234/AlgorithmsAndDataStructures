#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vii;
typedef pair<int,int> pii;
const ll mod=1000000007;

ll pwrmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll pwr(ll a,ll b){ll res=1;assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll eea(ll a,ll b,ll &x,ll &y){if(a == 0){x=0;y=1;return b;}ll x1, y1;ll d = eea(b%a, a, x1, y1);x=y1-(b/a)*x1;y=x1;return d;}
ll bsearch(ll a[],ll val,ll n){
    ll low = 1,high = n;
    while(low<=high){
        ll mid = low + (high-low)/2;
        if(a[mid] == val) return mid;
        else if(a[mid]<val) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

class compare{
    public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second > b.second;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<pair<int,ll> > > g;
    priority_queue<pair<int,ll>,vector<pair<int,ll> > ,compare> q;
    int n,m;
    cin>>n>>m;
    g.resize(n+2);
    for(int i=1 ; i<=m ; i++){
        ll w;
        int s,d;
        cin>>s>>d>>w;
        g[s].push_back(mp(d,2*w));
        g[d].push_back(mp(s,2*w));
    }
    ll dist[n+2];
    for(int i=1 ; i<=n ; i++) cin>>dist[i];
    for(int i=1 ; i<=n ; i++){
        g[i].push_back(mp(n+1,dist[i]));
        g[n+1].push_back(mp(i,dist[i]));
    }
    for(int i=1 ; i<=n ; i++) dist[i] = LONG_LONG_MAX;
    dist[n+1] = 0;
    q.push(mp(n+1,0));
    while(!q.empty()){
        int u = q.top().first;
        q.pop();
        for(int i=0 ; i<g[u].size() ; i++){
            if(dist[g[u][i].first] > dist[u] + g[u][i].second){
                dist[g[u][i].first] = dist[u] + g[u][i].second;
                q.push(mp(g[u][i].first,g[u][i].second));
            }
        }
    }
    for(int i=1 ; i<=n ; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
} 
