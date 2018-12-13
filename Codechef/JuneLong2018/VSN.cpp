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


class point{
    public:
    double x;
    double y;
    double z;
};

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

pair<dbl,dbl> solve_quadratic(dbl c, dbl b, dbl a){
    if(a==0) return {-c/b,-c/b};
    dbl ans1 = ( (-b + sqrt(pow(b,2) - 4*a*c )) / (2*a) );
    dbl ans2 = ( (-b - sqrt(pow(b,2) - 4*a*c) ) / (2*a) );
    return {ans1,ans2};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed;
    cout<<setprecision(8);
    int t;
    cin>>t;
    while(t--){
        point p,q,d,c;
        dbl rad;
        cin>>p.x>>p.y>>p.z;
        cin>>q.x>>q.y>>q.z;
        cin>>d.x>>d.y>>d.z;
        cin>>c.x>>c.y>>c.z;
        cin>>rad;
        dbl t_l = sqrt(pow(p.x-c.x,2) + pow(p.y-c.y,2) + pow(p.z-c.z,2) - pow(rad,2));
        dbl l = (c.x-p.x)*(c.x+p.x-2*q.x) + (c.y-p.y)*(c.y+p.y-2*q.y) + (c.z-p.z)*(c.z+p.z-2*q.z) - rad*rad - t_l*t_l;
        dbl g = 2*d.x*(p.x-c.x) + 2*d.y*(p.y-c.y) + 2*d.z*(p.z-c.z);
        //cout<<l<<" "<<g<<endl; 
        //quadratic eqn
        dbl ct = pow(l,2) - 4*pow(t_l,2)*(pow(q.x-p.x,2)+pow(q.y-p.y,2)+pow(q.z-p.z,2)); 
        dbl cf_t1 = 2*l*g - 8*pow(t_l,2)*((q.x-p.x)*d.x + (q.y-p.y)*d.y + (q.z-p.z)*d.z);
        dbl cf_t2 = pow(g,2) - 4*pow(t_l,2)*(pow(d.x,2)+pow(d.y,2)+pow(d.z,2));
        //cout<<ct<<" "<<cf_t1<<" "<<cf_t2<<endl;
        pair<dbl,dbl> ans = solve_quadratic(ct,cf_t1,cf_t2);   
        if(ans.first >= 0) cout<<ans.first<<endl;
        else if(ans.second >=0) cout<<ans.second<<endl;
    }

    return 0;
} 
