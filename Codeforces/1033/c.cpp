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
#define maxn 15000000

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

vector<ll> spf;

void sieve(){
    spf.assign(maxn,0);
    for(int i=2 ; i<=maxn ; i++) spf[i] = i;
    for(int i=2 ; i<=maxn ; i+=2) spf[i] = 2;
    for(int i=3 ; i*i<= maxn ; i++){
        if(spf[i] == i){
            for(int j=i*i ; j<=maxn ; j+=i) {
                if(spf[j] == j) spf[j] = i;  
            }
        }
    } 
}

vector<ll> getfactorization(ll x){
    vector<ll> fact;
    while(x != 1){
        fact.push_back(spf[x]);
        x = x/spf[x];
    }
    return fact;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n;
    cin>>n;
    map<ll,ll> m;
    map<ll,ll> ans;
    vector<ll> a(n+1,0);
    for(int i=1 ; i<=n ; i++) cin>>a[i], m[a[i]] = i;
    ans[1] = 1;
    ans[n] = 0;
    for(int i=n-1 ; i>1 ; i--){
        if((m[i] - m[n]) % i == 0){
            ans[i] = 1;
        }else{
            int p = m[i] - i;
            int q = m[i] + i;
            int c = 0;
            while(p >= 1){
                if(a[p] > i and ans.find(a[p]) != ans.end()){
                    if(ans[a[p]] == 0) c++;
                }
                p -= i;
                if(c > 0) break;
            }
            while(q <= n){
                if(a[q] > i and ans.find(a[q]) != ans.end()){
                    if(ans[a[q]] == 0) c++;
                }
                q += i;
                if(c > 0) break;
            }
            if( c > 0) ans[i]  = 1;
            else ans[i] = 0;
        }
    }

    string out="";
    for(int i=1 ; i<=n ; i++){
        if(ans[a[i]] == 1) out += "A";
        else out += "B";
    }

    cout<<out<<endl;
    return 0;   
} 
