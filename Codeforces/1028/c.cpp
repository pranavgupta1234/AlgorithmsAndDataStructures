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

vector<ll> x1;
vector<ll> x2;
vector<ll> xy1;
vector<ll> xy2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin>>n;

    for(int i=1 ; i<=n ; i++){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        x1.push_back(a);
        xy1.push_back(b);
        x2.push_back(c);
        xy2.push_back(d);
    }

    sort(x1.begin(),x1.end(),greater<ll>());
    sort(x2.begin(),x2.end());
    sort(xy1.begin(),xy1.end(), greater<ll>());
    sort(xy2.begin(),xy2.end());

    if(x1[0] <= x2[0] and xy1[0] <= xy2[0]) cout<<x1[0]<<" "<<xy1[0]<<endl;
    else if(x1[0] >= x2[0] and xy1[0] < xy2[0]) cout<<x1[1]<<" "<<xy1[0]<<endl;
    else if(x1[0] < x2[0] and xy1[0] >= xy2[0]) cout<<x1[0]<<" "<<xy1[1]<<endl;
    else if(x1[0] > x2[0] and xy1[0] > xy2[0]) cout<<x1[1]<<" "<<xy1[1]<<endl;

    return 0;
} 
