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
    ll n;
    cin>>n;
    vector<ll> arr(n+1,0);
    vector<ll> diff;
    for(int i=1 ; i<=n ; i++) cin>>arr[i];
    if(n<=2) cout<<0<<endl,exit(0);
    for(int i=1 ; i<arr.size()-1 ; i++) diff.push_back(arr[i+1]-arr[i]);   
    ll c = 0;
    vector< pair<int,int> > poss;
    vector< pair<int,int> > poss1;
    poss.push_back({arr[1]+1,arr[2]+1});
    poss.push_back({arr[1]+1,arr[2]-1});
    poss.push_back({arr[1]+1,arr[2]});
    poss.push_back({arr[1],arr[2]+1});
    poss.push_back({arr[1],arr[2]-1});
    poss.push_back({arr[1],arr[2]});
    poss.push_back({arr[1]-1,arr[2]+1});
    poss.push_back({arr[1]-1,arr[2]-1});
    poss.push_back({arr[1]-1,arr[2]});
    
    poss1.push_back({arr[2]+1,arr[3]+1});
    poss1.push_back({arr[2]+1,arr[3]-1});
    poss1.push_back({arr[2]+1,arr[3]});
    poss1.push_back({arr[2],arr[3]+1});
    poss1.push_back({arr[2],arr[3]-1});
    poss1.push_back({arr[2],arr[3]});
    poss1.push_back({arr[2]-1,arr[3]+1});
    poss1.push_back({arr[2]-1,arr[3]-1});
    poss1.push_back({arr[2]-1,arr[3]});
    ll fdif = LONG_LONG_MAX;
    ll inita,initb;
    for(int i=0 ; i<poss.size() ; i++) {
        for(int j=1 ; j<poss1.size() ; j++){
            if((poss[i].second-poss[i].first) == (poss1[j].second - poss1[j].first)){
                fdif = (poss[i].second-poss[i].first);
                inita = poss[i].first;
                initb = poss[i].second;
            }
        }
    }    
    if(fdif == LONG_LONG_MAX) cout<<-1<<endl,exit(0);
    vector<ll> corr(n+1,0);
    corr[1] = inita;
    for(int i=2 ; i<=n ; i++){
        if((arr[i+1] - arr[i]) != fdif) cout<<-1<<endl,exit(0);
    }
    for(int i=2 ; i<=n ; i++) corr[i] = corr[i-1] + fdif;
    for(int i=1 ; i<n ; i++){
        if(corr[i] != arr[i]) c++;
    }
    cout<<c<<endl;
    return 0;
} 