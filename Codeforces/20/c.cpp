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
int n,m;

ll pwrmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll pwr(ll a,ll b){ll res=1;assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll eea(ll a,ll b,ll &x,ll &y){ if(a == 0){x=0;y=1;return b;}ll x1, y1;ll d = eea(b%a, a, x1, y1);x=y1-(b/a)*x1;y=x1;return d;}
ll bsearch(ll a[],ll val,ll l,ll h){
    // for zero based indexing use 0 and n-1
    while(l<=h){
        ll mid = l + (h-l)/2;
        if(a[mid] == val) return mid;
        else if(a[mid]<val) l = mid+1;
        else h = mid-1;
    }
    return -1;  //not found
}

class compare{
    public:
    bool operator() (pair<int,int>& a,pair<int,int>& b){
        return a.second < b.second;
    }
};

int comp(pair<int,int>& a,pair<int,int>& b){
    return a.second < b.second;
}

int path(int par[],int v){
	if(v == -1) return -1;
    if(v){
		path(par,par[v]);
		printf("%d ",v);
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    vector<vector<pair<int,int> > > g;
    g.resize(n+10);
    for(int i=1 ; i<=m ; i++){
        int s,d,w;
        cin>>s>>d>>w;
        g[s].push_back(mp(d,w));
        g[d].push_back(mp(s,w));
    }
    for(int i=1 ; i<=n ; i++){
        sort(g[i].begin(),g[i].end(),comp);
    }
    priority_queue<pair<int,int>,vector<pair<int,int> > ,compare> q;
    q.push(mp(1,0));
    int d[n+10];
    int par[n+10];
    for(int i=0 ; i<=n ; i++) par[i] = -1;
    for(int i=1 ; i<=n ; i++) d[i] = INT_MAX - 10;
    d[1] = 0;
    while(!q.empty()){
        int v = q.top().first;
        q.pop();
        for(int i=0 ; i<g[v].size() ; i++){
            if(d[g[v][i].first] > d[v] + g[v][i].second){
                d[g[v][i].first] = d[v] + g[v][i].second;
                par[g[v][i].first] = v;
                q.push(mp(g[v][i].first,g[v][i].second));
            }
        }
    }
    vector<int> ans;
    bool f = false;
    for(int i=n ; i!=1 ; i=par[i]){
        if(i == -1) { f = true ; break; }  
        else ans.push_back(i);
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    if(f) cout<<-1<<endl;
    else{
        for(int i=0 ; i<ans.size() ; i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
} 
