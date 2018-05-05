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
const int N = 5005;
int n,m;
int d[N][N];
vector<int> g[N];

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(d,-1,sizeof d);
    cin>>n>>m;
    for(int i=1 ; i<=m ; i++){
        int s,d;
        cin>>s>>d;
        g[s].push_back(d);
        g[d].push_back(s);
    }
    //all pair shortest path O(n^2) using bfs from each node 
    for(int i=1 ; i<=n ; i++){
        queue<int> q;
        d[i][i] = 0;
        q.push(i);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int j=0 ; j<g[v].size() ; j++){
                if(d[i][g[v][j]] == -1){
                    d[i][g[v][j]] = d[i][v] + 1;
                    q.push(g[v][j]);
                }
            }
        }
    }
    int ans = m+1;
    int s[2],t[2],l[2];
    cin>>s[0]>>t[0]>>l[0];
    cin>>s[1]>>t[1]>>l[1];
    for(int it=0 ; it<2 ; it++){
        swap(s[0],t[0]);
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                int v[] = {d[s[0]][i] + d[i][j] + d[j][t[0]], d[s[1]][i] + d[i][j] + d[j][t[1]]};
                if(v[0] <= l[0] and v[1] <= l[1]){
                    ans = min(ans,v[0]+v[1]-d[i][j]);
                }
            }
        }
    }
    if(d[s[0]][t[0]] <= l[0] and d[s[1]][t[1]] <=l[1]){
        ans = min(ans,d[s[0]][t[0]] + d[s[1]][t[1]]);
    }
    if(ans > m) cout<<-1<<endl;
    else cout<<m-ans<<endl;
} 
