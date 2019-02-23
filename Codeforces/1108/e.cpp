#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define F first
#define S second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n+1, 0);
    vector<pair<ll,ll> > s(m+1, {0, 0});
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    vector<ll> cp(a.begin(), a.end());
    for(int i=1 ; i<=m ; i++){
        cin>>s[i].F>>s[i].S;
    }

    ll diff = 0;
    vector<ll> ans;
    for(int i=1 ; i<=n ; i++){
        ll val = a[i];
        vector<ll> taken;
        for(int j=1 ; j<=m ; j++){
            if(i >= s[j].F and i <= s[j].S){
                continue;
            }
            for(int k=s[j].F ; k<=s[j].S ; k++) a[k]--;
            taken.push_back(j);
        }
        ll mn = INT_MAX;
        for(int j=1 ; j<=n ; j++){
            if(i == j) continue;
            mn = min(mn, a[j]);
        }
        if(val - mn > diff){
            diff = val - mn;
            ans = taken;
        }
        for(int i=1 ; i<=n ; i++) a[i] = cp[i];
    }

    cout<<diff<<endl;
    cout<<ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for(auto i : ans) cout<<i<<" ";
    cout<<endl;
    return 0;
} 
