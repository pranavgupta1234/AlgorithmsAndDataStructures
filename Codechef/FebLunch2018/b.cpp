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
ll eea(ll a,ll b,ll &x,ll &y){ if(a == 0){x=0;y=1;return b;}ll x1, y1;ll d = eea(b%a, a, x1, y1);x=y1-(b/a)*x1;y=x1;return d;}
ll bsearch(vector<ll>& a,ll val){
    ll low = 0,high = a.size()-1;
    while(low<=high){
        ll mid = low + (high-low)/2;
        if(a[mid] == val) return mid;
        else if(a[mid]<val) low = mid+1;
        else high = mid-1;
    }
    return -1;  //not found
}

bool comp(pair<ll,ll>& a,pair<ll,ll>& b){
    return a.first<b.first;
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<pair<ll,ll> > ad(n+1);
        ll b[k+1];
        ll cma[n+1];
        vector<ll> cmd(n+1);
        ll tot = 0;
        for(int i=1 ; i<=n ; i++){
            cin>>ad[i].first;
        }
        for(int i=1 ; i<=n ; i++){
            cin>>ad[i].second;
            tot += ad[i].second;
        }
        for(int i=1 ; i<=k ; i++) cin>>b[i];
        sort(ad.begin(),ad.end(),comp);
        ad[0] = mp(0,0);
        cma[0] = 0;
        cma[1] = ad[1].first*ad[1].second;
        cmd[0] = 0,cmd[1] = ad[1].second;
        for(int i=2 ; i<=n ; i++) cma[i] = ad[i].first*ad[i].second + cma[i-1];
        for(int i=2 ; i<=n ; i++) cmd[i] = ad[i].second + cmd[i-1];
        ll i=1,j=tot;
        ll ans = 0;
        for(int p=1 ; p<=k ; p++){
            if(p&1){
                i = j - b[p];
                //cout<<i<<endl;
            }else{
                j = i + b[p];
                //cout<<j<<endl;
            }
        }
        //cout<<i<<" "<<j<<endl;
        ll u1=0,u2=0;
        ll ex1=0,ex2=0;
        if(binary_search(cmd.begin(),cmd.end(),i) == false){
            u1 = upper_bound(cmd.begin(),cmd.end(),i) - cmd.begin();
            ex1 = cmd[u1] - i;
        }else u1 = bsearch(cmd,i);
        if(binary_search(cmd.begin(),cmd.end(),j) == false){
            u2 = upper_bound(cmd.begin(),cmd.end(),j) - cmd.begin();
            ex2 = cmd[u2] - j;
        }else u2 = bsearch(cmd,j);
        //cout<<u1<<" "<<u2<<" "<<ex1<<" "<<ex2<<endl;
        cout<<cma[u2]-ex2*ad[u2].first-cma[u1]+ex1*ad[u1].first<<endl;
    }
    return 0;
} 