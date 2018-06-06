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
    string kuro,shiro,katie;
    cin>>kuro>>shiro>>katie;
    map<char,ll> m1,m2,m3;
    ll l = kuro.length();
    for(int i=0 ; i<kuro.length() ; i++){
        m1[kuro[i]]++;
        m2[shiro[i]]++;
        m3[katie[i]]++;
    }
    ll mx1 = -1,mx2 = -1,mx3 = -1;
    for(auto &it : m1){
        mx1 = max(mx1,it.second);
    }
    for(auto &it : m2){
        mx2 = max(mx2,it.second);
    }
    for(auto &it : m3){
        mx3 = max(mx3,it.second);
    }
    int x=0,y=0,z=0;
    x = l-mx1;
    y = l-mx2;
    z = l-mx3;

    ll minstep = min(x,min(y,z));
    ll maxstep = max(x,max(y,z));
    if(n < minstep) {
        if(mx1 > mx2 and mx1 > mx3) cout<<"Kuro"<<endl;
        else if(mx2 > mx3 and mx2 > mx1) cout<<"Shiro"<<endl;
        else if(mx3 > mx2 and mx3 > mx1) cout<<"Katie"<<endl;
        else cout<<"Draw"<<endl;  
    }else if(n > maxstep){
        ll ans1,ans2,ans3;
        if((n-x) & 1) ans1 = l-1;
        else ans1 = l;
        if((n-y) & 1) ans2 = l-1;
        else ans2 = l;
        if((n-z) & 1) ans3 = l-1;
        else ans3 = l;

        if(ans1 > ans2 and ans1 > ans3) cout<<"Kuro"<<endl;
        else if(ans2 > ans3 and ans2 > ans1) cout<<"Shiro"<<endl;
        else if(ans3 > ans2 and ans3 > ans1) cout<<"Katie"<<endl;
        else cout<<"Draw"<<endl;

    }else{
        mx1 += minstep-1;
        mx2 += minstep-1;
        mx3 += minstep-1;
        for(int i=minstep ; i<=n ; i++){
            mx1++;
            if(mx1 == l+1) mx1 = l-1;
            mx2++;
            if(mx2 == l+1) mx2 = l-1;
            mx3++;
            if(mx3 == l+1) mx3 = l-1;
        }

        if(mx1 > mx2 and mx1 > mx3) cout<<"Kuro"<<endl;
        else if(mx2 > mx3 and mx2 > mx1) cout<<"Shiro"<<endl;
        else if(mx3 > mx2 and mx3 > mx1) cout<<"Katie"<<endl;
        else cout<<"Draw"<<endl;
    }
    return 0;
} 
