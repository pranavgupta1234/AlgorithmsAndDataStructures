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
    cout<<fixed;
    cout<<setprecision(12);
    int t;
    cin>>t;
    while(t--) {
        ll n,s,w;
        cin>>n>>s>>w;
        dbl v[n+1],d[n+1],p[n+1],c[n+1];
        for(int i=1 ; i<=n ; i++) cin>>v[i];
        for(int i=1 ; i<=n ; i++) cin>>d[i];
        for(int i=1 ; i<=n ; i++) cin>>p[i];
        for(int i=1 ; i<=n ; i++) cin>>c[i];
        dbl time_cross = 1.0*w/s;
        dbl time_taken = 0.0;
        for(int i=1 ; i<=n ; i++){
            dbl t_elapsed = 0;
            if(d[i] == 1){
                if((p[i] >= 0 and p[i]-c[i] < 0) or p[i] < 0){
                    dbl time_nearest_pt;
                    if(p[i] < 0) time_nearest_pt = abs(p[i])/v[i];
                    else time_nearest_pt = 0;
                    
                    if(time_nearest_pt - time_cross > 1e-6) t_elapsed += time_cross;
                    else t_elapsed += (time_cross + abs(-1*p[i]+c[i])/v[i]);
                }
            }else{
                if((p[i] <= 0 and abs(p[i])-c[i] < 0)  or p[i] > 0){
                    dbl time_nearest_pt;
                    if(p[i] > 0) time_nearest_pt = abs(p[i])/v[i];
                    else time_nearest_pt = 0;

                    if(time_nearest_pt - time_cross > 1e-6) t_elapsed += time_cross;
                    else t_elapsed += (time_cross + (p[i] + c[i])/v[i]);
                }
            } 
            if(t_elapsed == 0) t_elapsed = time_cross;
            time_taken += t_elapsed;
            for(int j=1 ; j<=n ; j++){
                if(d[j] == 1){
                    p[j] += v[j]*t_elapsed;
                }else{
                    p[j] -= v[j]*t_elapsed; 
                }
            }
        }
        cout<<time_taken<<endl;
    }
    return 0;
} 
