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

#define MAXN 15000100 
  
// stores smallest prime factor for every number 
int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() { 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
map<ll,ll> getFactorization(int x) 
{ 
    map<ll,ll> ret; 
    while (x != 1) 
    { 
        ret[spf[x]]++; 
        x = x / spf[x]; 
    } 
    return ret; 
} 
  

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin>>n;

    vector<ll> a(n,0);
    ll g = 1;
    ll o = 0;
    set<ll> s;
    for(int i=0 ; i<n ; i++){
        cin>>a[i];
        if(i == 0) g = a[i];
        g = __gcd(g, a[i]);
        if(a[i] == 1) o++;
        s.insert(a[i]);
    } 

    if(n == 2 and a[0] != a[1]) cout<<1<<endl,exit(0);
    if(n == 2 and a[0] == a[1]) cout<<-1<<endl,exit(0);  
    if(s.size() == 1) cout<<-1<<endl,exit(0);
    sieve();
    map<ll,ll> overall;
    ll ans = 0;
    bool f = true;
    if(g == 1) ans += o;
    else{
        for(int i=0 ; i<n ; i++){
            map<ll,ll> m = getFactorization(a[i]);
            map<ll,bool> vis;
            for(auto i : m){
                vis[i.first] = false;
            }
            for(auto i : m){
                if(vis[i.first] == false){
                    overall[i.first]++;
                    vis[i.first] = true;
                }
            }
        }
        ll mx = 1;
        for(auto i : overall){
            if(i.first != g) mx = max(mx, i.second);
        }
        ans = n - mx;
    }

    //for(int i=0 ; i<n ; i++) cout<<a[i]<<" ";
    cout<<ans<<endl;


    return 0;
} 