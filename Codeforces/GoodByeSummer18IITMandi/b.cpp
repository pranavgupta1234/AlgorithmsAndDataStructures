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

ll bsearch(ll a[],ll val,ll l,ll h){
    while(l<=h){
        ll mid = l + (h-l)/2;
        if(a[mid] == val) return mid;
        else if(a[mid]<val) l = mid+1;
        else h = mid-1;
    }
    return -1;
}

ll n,m;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    vector<int> a(n,0);
    int o=0,e=0;
    int z = 0;  
    for(int i=0 ; i<n ; i++) {
        cin>>a[i];
        if(a[i] & 1) o++;
        else e++;

        if(a[i] == 0) z++;
    }
    if(n == 1 and m == 1 and a[0] & 1) cout<<0<<endl,exit(0);
    if(n == 1 and m == 1 and !(a[0] & 1)) cout<<1<<endl,exit(0);
    if(n == 1 and m > n) cout<<0<<endl,exit(0);    
    ll ans = 1;
    for(int i=0 ; i<m ; i++){
        if(i == 0) {
            ans *= (e-z);
            continue;
        }
        if(i & 1) ans *= o;
        else ans *= e;
    }
    cout<<ans<<endl;
    return 0;
} 
