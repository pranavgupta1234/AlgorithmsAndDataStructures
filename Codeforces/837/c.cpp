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

    int n,a,b;
    cin>>n>>a>>b;
    vector<pair<int,int> > v; 
    for(int i=0 ; i<n ; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    int ans = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i != j){
                int x1 = v[i].first;
                int y1 = v[i].second;
                int x2 = v[j].first;
                int y2 = v[j].second;
                //top left and bottom right
                if(x1 + x2 <= a and y1 <= b and y2 <= b) ans = max(ans,x1*y1+x2*y2);
                else if(y1 + y2 <= b and x1 <= a and x2 <= a) ans = max(ans,x1*y1+x2*y2);
                swap(x2,y2);
                if(x1 + x2 <= a and y1 <= b and y2 <= b) ans = max(ans,x1*y1+x2*y2);
                else if(y1 + y2 <= b and x1 <= a and x2 <= a) ans = max(ans,x1*y1+x2*y2);
                swap(x1,y1);
                if(x1 + x2 <= a and y1 <= b and y2 <= b) ans = max(ans,x1*y1+x2*y2);
                else if(y1 + y2 <= b and x1 <= a and x2 <= a) ans = max(ans,x1*y1+x2*y2);
                swap(x2,y2);
                if(x1 + x2 <= a and y1 <= b and y2 <= b) ans = max(ans,x1*y1+x2*y2);
                else if(y1 + y2 <= b and x1 <= a and x2 <= a) ans = max(ans,x1*y1+x2*y2);
                
/*                 //top right and bottom left
                if(x1 + x2 <= a and y1 <= b and y2 <= b) ans = max(ans,x1*y1+x2*y2);
                else if(y1 + y2 <= b and x1 <= a and x2 <= a) ans = max(ans,x1*y1+x2*y2);
                swap(x2,y2);
                if(x1 + x2 <= a and y1 <= b and y2 <= b) ans = max(ans,x1*y1+x2*y2);
                else if(y1 + y2 <= b and x1 <= a and x2 <= a) ans = max(ans,x1*y1+x2*y2);
                swap(x1,y1);
                if(x1 + x2 <= a and y1 <= b and y2 <= b) ans = max(ans,x1*y1+x2*y2);
                else if(y1 + y2 <= b and x1 <= a and x2 <= a) ans = max(ans,x1*y1+x2*y2);
                swap(x2,y2);
                if(x1 + x2 <= a and y1 <= b and y2 <= b) ans = max(ans,x1*y1+x2*y2);
                else if(y1 + y2 <= b and x1 <= a and x2 <= a) ans = max(ans,x1*y1+x2*y2); */
            }
        }
    }

    cout<<ans<<endl;

    return 0;
} 
