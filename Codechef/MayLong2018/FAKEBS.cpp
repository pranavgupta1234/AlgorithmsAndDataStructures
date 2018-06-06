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
        int n,q;
        cin>>n>>q;
        vector<ll> num(n,0);
        ll mn = __INT_MAX__,mx = -1;
        map<ll,ll> hash;
        for(int i=0 ; i<n ; i++) cin>>num[i],hash[num[i]] = i;
        for(int i=0 ; i<n ; i++){
            mn = min(mn,num[i]);
            mx = max(mx,num[i]);
        }   
        while(q--){
            ll x;
            cin>>x;
            vector<ll> pivots;
            ll idx = hash[x];
            ll l = 0,r = n-1;
            ll swaps = 0;               //max can be logn swaps
            bool f = false;
            while(l <= r){
                ll mid = l + (r-l)/2;
                if(num[mid] == x){
                    f = true;
                    swaps = 0;
                    break;
                }else if(num[mid] < x){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            l = 0,r = n-1;
            while(l<=r and !f){
                ll mid = l + (r-l)/2;
                if(num[mid] == x) break;
                if(num[mid] > x and mn == x) {
                    swaps = -1;
                    break;
                }
                if(num[mid] < x and mx == x) {
                    swaps = -1;
                    break;
                }
                if(num[mid] == x) break;
                else if(num[mid] > x) {
                    if(idx > mid){
                        l = mid+1;
                        pivots.push_back(num[mid]);
                    }else{
                        r = mid-1;
                    }
                }else {
                    if(idx < mid){
                        r = mid-1;
                        pivots.push_back(num[mid]);
                    }else{
                        l = mid+1;    
                    }   
                }
            }
            if(swaps != -1) swaps = pivots.size();
            if(pivots.size() >=2){
                for(int i=0 ; i<=pivots.size()-2 ; i+=2){
                    if(pivots[i] > x and pivots[i+1] < x) swaps--;
                    if(pivots[i] < x and pivots[i+1] > x) swaps--;
                }
            }
            cout<<swaps<<endl;
        }
    }
    return 0;
} 
