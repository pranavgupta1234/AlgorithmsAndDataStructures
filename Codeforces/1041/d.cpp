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
    cin.tie(0);
    cout.tie(0);
    ll n,h1;
    cin>>n>>h1;
    vector<pair<ll,ll> > v;
    vector<ll> seg;    
    vector<ll> gaps;
    for(int i=0 ; i<n ; i++){
        ll x1,x2;
        cin>>x1>>x2;
        v.push_back({x1,x2});
        seg.push_back(x2-x1);
    }
    for(int i=0 ; i<n-1 ; i++){
        gaps.push_back(v[i+1].first - v[i].second);
    }
    gaps.push_back(0);
    gaps.push_back(0);
    int i=0,j=0;
    ll ht = h1;
    ll ans = 0;
    ll d = 0;
    ll r = 0;
    if(n == 1){
        cout<<v[0].second - v[0].first+1 + h1-1 <<endl;
        exit(0);
    }
    while(i < n and j < n){
        while(j < n and ht > 0){
            d += seg[j];
            if(ht < gaps[j]) r = gaps[j] - ht;
            d += min(ht,gaps[j]);
            ht -= min(ht,gaps[j]);
            j++;
        }
        //cout<<d<<endl;
        if(ht > 0) d += ht;
        ans = max(ans, d);
        d -= gaps[i];
        d -= seg[i];
        ht += gaps[i];
        d += r; 
        ht -= r; 
        i++;
    }

    cout<<ans<<endl;

    return 0;
} 
