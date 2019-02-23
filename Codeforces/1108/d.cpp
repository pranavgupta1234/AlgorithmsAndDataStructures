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

    int n;
    cin>>n;

    string str;
    cin>>str;

    if(n == 1){
        cout<<0<<endl;
        cout<<str<<endl;
        exit(0);
    }

    if(n == 2){
        if(str[0] == str[1]){
            cout<<1<<endl;
            if(str[0] == 'G') str[0] = 'B'; 
            if(str[0] == 'B') str[0] = 'G'; 
            if(str[0] == 'R') str[0] = 'G'; 
            cout<<str<<endl;
            exit(0);
        }else{
            cout<<0<<endl;
            cout<<str<<endl;
            exit(0);
        }
    }
    ll cnt = 0;
    for(int i=0 ; i<n-1 ; i++){
        if(str[i] != str[i+1]){
            continue;
        }
        if(i+2 < n){
            if(str[i+1] == str[i+2]){
                if(str[i+1] == 'B') str[i+1] = 'G', cnt++;
                else if(str[i+1] == 'G') str[i+1] = 'B', cnt++;
                else if(str[i+1] == 'R') str[i+1] = 'G', cnt++;;
            }else {
                if(str[i] == 'R' and str[i+1] == 'R' and str[i+2] == 'G'){
                    str[i+1] = 'B';
                    cnt++;
                }else if(str[i] == 'R' and str[i+1] == 'R' and str[i+2] == 'B'){
                    str[i+1] = 'G';
                    cnt++;
                }
                else if(str[i] == 'G' and str[i+1] == 'G' and str[i+2] == 'R'){
                    str[i+1] = 'B';
                    cnt++;
                }
                else if(str[i] == 'G' and str[i+1] == 'G' and str[i+2] == 'B'){
                    str[i+1] = 'R';
                    cnt++;
                }
                else if(str[i] == 'B' and str[i+1] == 'B' and str[i+2] == 'G'){
                    str[i+1] = 'R';
                    cnt++;
                }
                else if(str[i] == 'B' and str[i+1] == 'B' and str[i+2] == 'R'){
                    str[i+1] = 'G';
                    cnt++;
                }
            }
        }else{
            if(str[i] == 'G') str[i+1] = 'B';
            if(str[i] == 'B') str[i+1] = 'R';
            if(str[i] == 'R') str[i+1] = 'G';
            cnt++;
        }
    }
    cout<<cnt<<endl;
    cout<<str<<endl;
    return 0;
} 
