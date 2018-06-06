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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll m,n;
        cin>>m>>n;
        vector<ll> a(m+1,0);
        vector<ll> b(m+1,0);
        vector<ll> fib(100010,0);
        ll res = 0;
        fib[1] = 1;
        for(int i=1 ; i<=m ; i++) cin>>a[i];
        for(int i=1 ; i<=m ; i++) cin>>b[i];
        for(int i=2 ; i<=100009 ; i++){
            fib[i] = (fib[i-1]%mod + fib[i-2]%mod)%mod;
            fib[i] = fib[i]%mod;
        }
        sort(a.begin()+1,a.end());
        for(int i=1 ; i<=m ; i++){
            if(n == 1) res += a[1];
            else if(n == 2) res += b[i];
            else res += ((fib[n-1]*b[i])%mod + (fib[n-2]*a[1])%mod)%mod;
            res = res % mod;
        }
        ll temp = res;
        for(int i=2 ; i<=m ; i++){
            if(n == 1) res += m*a[i]%mod;
            else if(n == 2) res += temp;
            else res += ((((m*fib[n-2])%mod)*((a[i]-a[1])%mod))%mod+temp%mod)%mod;
            res = res%mod;
        }
        cout<<res<<endl;
    }
    return 0;
} 
