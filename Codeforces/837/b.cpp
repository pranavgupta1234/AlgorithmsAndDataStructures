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

    int n,m;
    cin>>n>>m;

    vector<vector<char> > f(n, vector<char> (m,'1'));
    for(int i=0 ; i<n ; i++){
        string str;
        cin>>str;
        for(int j=0 ; j<m ; j++){
            f[i][j] = str[j];
        }
    }

    if(n % 3 != 0 and m % 3 != 0 ) cout<<"NO"<<endl,exit(0);
    bool ans = true;
    if(n % 3 == 0 and m % 3 == 0){
        int w1 = m/3;
        char a = f[0][0];
        char b = f[0][w1];
        char c = f[0][2*w1];
        bool f1 = true;
        bool f2 = true;
        if(a == b or b == c or c == a){
            f1 = false;
        }
        for(int i=0 ; i<w1 ; i++){
            for(int j=0 ; j<n ; j++){
                if(f[j][i] != a){
                    f1 = false;
                }
            }
        }
        for(int i=w1 ; i<2*w1 ; i++){
            for(int j=0 ; j<n ; j++){
                if(f[j][i] != b){
                    f1 = false;
                }
            }
        }
        for(int i=2*w1 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(f[j][i] != c){
                    f1 = false;
                }
            }
        }
        int w = n/3;
        a = f[0][0];
        b = f[w][0];
        c = f[2*w][0];
        if(a == b or b == c or a == c) {
            f2 = false;
        }
        for(int i=0 ; i<w ; i++){
            for(int j=0 ; j<m ; j++){
                if(f[i][j] != a){
                    f2 = false;
                }
            }
        }
        for(int i=w ; i<2*w ; i++){
            for(int j=0 ; j<m ; j++){
                if(f[i][j] != b){
                    f2 = false;
                }
            }
        }
        for(int i=2*w ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(f[i][j] != c){
                    f2 = false;
                }
            }
        }
        if(f1 or f2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        exit(0);
    }
    if(n % 3 == 0){
        int w = n/3;
        char a = f[0][0];
        char b = f[w][0];
        char c = f[2*w][0];
        if(a == b or b == c or a == c) {
            cout<<"NO"<<endl;
            exit(0);
        }
        for(int i=0 ; i<w ; i++){
            for(int j=0 ; j<m ; j++){
                if(f[i][j] != a){
                    cout<<"NO"<<endl;
                    exit(0);
                }
            }
        }
        for(int i=w ; i<2*w ; i++){
            for(int j=0 ; j<m ; j++){
                if(f[i][j] != b){
                    cout<<"NO"<<endl;
                    exit(0);
                }
            }
        }
        for(int i=2*w ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(f[i][j] != c){
                    cout<<"NO"<<endl;
                    exit(0);
                }
            }
        }
    }
    if(m % 3 == 0){
        int w = m/3;
        char a = f[0][0];
        char b = f[0][w];
        char c = f[0][2*w];
        if(a == b or b == c or a == c) {
            cout<<"NO"<<endl;
            exit(0);
        }
        for(int i=0 ; i<w ; i++){
            for(int j=0 ; j<n ; j++){
                if(f[j][i] != a){
                    cout<<"NO"<<endl;
                    exit(0);
                }
            }
        }
        for(int i=w ; i<2*w ; i++){
            for(int j=0 ; j<n ; j++){
                if(f[j][i] != b){
                    cout<<"NO"<<endl;
                    exit(0);
                }
            }
        }
        for(int i=2*w ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(f[j][i] != c){
                    cout<<"NO"<<endl;
                    exit(0);
                }
            }
        }
    } 

    cout<<"YES"<<endl;
    return 0;
} 
