#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define F first
#define S second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
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
    spf.assign(15000000,0);
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

    string str;
    cin>>str;

    map<char,ll> m;
    int n = str.length();

    for(int i=0 ; i<n ; i++) m[str[i]]++;
    
    vector<ll> pref(n+1, 0);
    vector<ll> colon;
    for(int i=1 ; i<=n ; i++) {
        if(str[i-1] == '|') pref[i] = pref[i-1] + 1;
        else pref[i] = pref[i-1];
    }
    for(int i=0 ; i<n ; i++){
        if(str[i] == ':') colon.push_back(i);
    }
    int i=0,j=n-1;

    while(i < j){
        if(str[i] != '['){
            i++;
            continue;
        }
        if(str[j] != ']'){
            j--;
            continue;
        }

        int c1 = upper_bound(colon.begin(), colon.end(), i) - colon.begin();
        int c2 = lower_bound(colon.begin(), colon.end(), j) - colon.begin() -1 ; 
        //cout<<colon[c1]<<" "<<colon[c2]<<endl;
        if(c2 >= 0 and colon[c1] < j and colon[c2] > i and colon[c1] < colon[c2]){
            cout<<4+pref[colon[c2]+1]-pref[colon[c1]]<<endl;
            exit(0);
        } else{
            i++;
            j--;
        }

    }
    
    cout<<-1<<endl;

    return 0;
} 
