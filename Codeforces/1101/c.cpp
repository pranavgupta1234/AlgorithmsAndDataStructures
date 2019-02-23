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
typedef vector<ll> vi;
typedef vector<ll> vii;
typedef pair<ll,ll> pii;
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

inline bool disj(pair<ll,ll>& a, pair<ll,ll>& b){
    if(a.S < b.F) return true;
    if(a.F > b.S) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        vector<pair<pii,pii> > a(n, {{0, 0}, {0, 0}});
        for(int i=0 ; i<n ; i++){
            cin>>a[i].F.F>>a[i].F.S;
            a[i].S.S = i;
        }

        sort(a.begin(), a.end(), [](pair<pii,pii>& a, pair<pii,pii>& b){
            if(a.F.S == b.F.S){
                return a.F.F < b.F.F;
            }else{
                return a.F.S < b.F.S;
            }
        });

        vector<ll> mn(n, 0);
        mn[n-1] = a[n-1].F.F;

        for(int i=n-2 ; i>=0 ; i--){
            mn[i] = min(a[i].F.F, mn[i+1]);
        }

        ll ans = -1;
        
        for(int i=0 ; i<n-1 ; i++){
            if(a[i].F.S < mn[i+1]){
                ans = i;
                break;
            }
        }

        if(ans == -1){
            cout<<-1<<endl;
            continue;
        } 

        for(int j=0 ; j<n ; j++){
            if(j <= ans) a[j].S.F = 1;
            else a[j].S.F = 2;
        }

        sort(a.begin(), a.end(), [](pair<pii,pii>& a, pair<pii,pii>& b){
            return a.S.S < b.S.S;
        });

        for(int i=0 ; i<n ; i++) cout<<a[i].S.F<<" ";
        cout<<endl;

    }
    


    return 0;
} 
