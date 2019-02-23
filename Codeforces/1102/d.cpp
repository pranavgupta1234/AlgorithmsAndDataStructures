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

    map<char,int> m;

    for(int i=0 ; i<n ; i++) m[str[i]]++;

    if(m['1'] == n/3 and m['1'] == m['2'] and m['2'] == m['0']){
        cout<<str<<endl;
        exit(0);
    } 

    if(m['2'] != n/3){
        int a = max(0, n/3 - m['0']);
        int b = max(0, n/3 - m['1']);

        int f_2_0 = ((a*1.0)*(m['2'] - n/3))/(a+b);
        int f_2_1 = ((b*1.0)*(m['2'] - n/3))/(a+b);

        int i=0;
        while(i < n and f_2_0 > 0){
            if(str[i] == '2'){
                str[i] = '0';
                f_2_0--;
            }
            i++;
        }
        i=0;
        while(i < n and f_2_1 > 0){
            if(str[i] == '2'){
                str[i] = '1';
                f_2_1--;
            }
            i++;
        }
    }

    if(m['0'] != n/3){
        int a = max(0, n/3 - m['1']);
        int b = max(0, n/3 - m['2']);

        int f_0_1 = ((a*1.0)*(m['0'] - n/3))/(a+b);
        int f_0_2 = ((b*1.0)*(m['0'] - n/3))/(a+b);

        int i=n-1;
        while(i >= 0 and f_0_2 > 0){
            if(str[i] == '0'){
                str[i] = '2';
                f_0_2--;
            }
            i--;
        }
        i=n-1;
        while(i >= 0 and f_0_1 > 0){
            if(str[i] == '0'){
                str[i] = '1';
                f_0_1--;
            }
            i--;
        }
    }

    if(m['1'] != n/3){
        int a = max(0, n/3 - m['0']);
        int b = max(0, n/3 - m['2']);

        int f_1_0 = ((a*1.0)*(m['1'] - n/3))/(a+b);
        int f_1_2 = ((b*1.0)*(m['1'] - n/3))/(a+b);

        int i=0;
        while(i < n and f_1_0 > 0){
            if(str[i] == '1'){
                str[i] = '0';
                f_1_0--;
            }
            i++;
        }
        i=n-1;
        while(i >= 0 and f_1_2 > 0){
            if(str[i] == '1'){
                str[i] = '2';
                f_1_2--;
            }
            i--;
        }
    }

    cout<<str<<endl;


    return 0;   
} 
