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
    while(t--) {
        ll n;
        string s;
        cin>>s>>n;
        ll pref[s.length()+10];
        ll a=0,b=0;
        pref[0] = 0;
        ll corr = 0;
        ll mx = INT_MIN,mn = INT_MAX;
        for(int i=1 ; i<=s.length() ; i++){
            if(s[i-1] == 'a') pref[i] = pref[i-1]+1,a++;
            else pref[i] = pref[i-1] - 1,b++;
            if(pref[i] >= 1) corr++;
        }
        for(int i=1 ; i<=s.length() ; i++) mx = max(mx,pref[i]),mn = min(mn,pref[i]);
        ll delta = abs(a-b);
        if(a == b) cout<<corr*n<<endl;
        else if(a < b) {
            for(ll i=2 ; i<=n ; i++){
                ll corr_dump = corr;
                for(int i=1 ; i<=s.length() ; i++){
                    pref[i] -= delta;
                    if(pref[i] >= 1) corr++;
                }
                if(corr_dump == corr) break;
            }
            cout<<corr<<endl;
        }else {
            ll i;
            ll corr_1 = corr;
            bool f = false;
            for(i=2 ; i<=n ; i++){
                ll corr_dump = corr;
                for(int i=1 ; i<=s.length() ; i++){
                    pref[i] += delta;
                    if(pref[i] >= 1) corr++;
                }
                if(corr_dump + s.length() == corr){
                    f = true;
                    break;
                }
            }
            if(n == 1) cout<<corr_1<<endl;
            else if(!f) cout<<corr<<endl;
            else cout<<corr+abs(n-i)*s.length()<<endl;
        }
    }
    return 0;
} 
