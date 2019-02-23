 
#pragma GCC optimize ("Ofast,unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define ff  first
#define ss second
#define tm1 first
#define tm2 second.first
#define tm3 second.second
#define sz(x) ll(x.size())
#define fill(x, v) memset(x, v, sizeof(x))
#define all(v) (v).begin(), (v).end()
#define FER(i,a,b) for(ll i=ll(a); i< ll(b); ++i)
#define IFR(i,a,b) for(ll i=ll(a); i>=ll(b); --i )
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
 
#define N 200015
#define mod 1000000007
#define N1 105
#define sqr(x) (x)*(x)
#define INF 2000000000000000000 
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii > tri;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;
 
#define trace(...) f(#__VA_ARGS__, __VA_ARGS__)
 
template<typename t> void f(const char* x, t&& val1){
    cout<<x<< " : "<<val1<<endl;
}
template<typename t1, typename... t2> void f(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    f(xd+1, val2...);
}

ll dp[N][1<<2];

inline ll go(ll l, ll r){
    if(l<0 && r<0) return 0;
    ll t1=l/3, t2=r/3;
    if(l<0) return t2+1;
    if(l%3) return t2-t1;
    return t2-t1+1;
}

int main(){
    fastio;
    ll n, l, r; cin>>n>>l>>r;
    // trace(n, l, r);
    ll cnt1=go(l, r), cnt2=go(l-1, r-1), cnt3=go(l-2, r-2);
    dp[0][0]=cnt1;
    dp[0][1]=cnt2;
    dp[0][2]=cnt3;
    FER(i,1,n){
        dp[i][0]=((dp[i-1][1]*cnt3)%mod+(dp[i-1][2]*cnt2)%mod+(dp[i-1][0]*cnt1)%mod)%mod;
        dp[i][1]=((dp[i-1][1]*cnt1)%mod+(dp[i-1][2]*cnt3)%mod+(dp[i-1][0]*cnt2)%mod)%mod;    
        dp[i][2]=((dp[i-1][1]*cnt2)%mod+(dp[i-1][2]*cnt1)%mod+(dp[i-1][0]*cnt3)%mod)%mod;
    }
    ll ja=dp[n-1][0];
    // trace(ja);
    cout<<ja<<endl;
    return 0;
}
