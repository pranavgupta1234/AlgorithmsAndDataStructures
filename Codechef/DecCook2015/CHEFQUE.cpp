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
typedef vector<int> vi;
typedef vector<ll> vii;
typedef pair<int,int> pii;
const ll mod=1000000007;
typedef tree<ll, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;

ll pwrmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll pwr(ll a,ll b){ll res=1;assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll eea(ll a,ll b,ll &x,ll &y){ if(a == 0){x=0;y=1;return b;}ll x1, y1;ll d = eea(b%a, a, x1, y1);x=y1-(b/a)*x1;y=x1;return d;}
ll bsearch(ll a[],ll val,ll l,ll h){
    // for zero based indexing use 0 and n-1
    while(l<=h){
        ll mid = l + (h-l)/2;
        if(a[mid] == val) return mid;
        else if(a[mid]<val) l = mid+1;
        else h = mid-1;
    }
    return -1;  //not found
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll q,s,a,b;
        cin>>q>>s>>a>>b;
        ll md = pwr(2,32);
        ll sum = 0;
        unordered_map<ll,bool> m;
        for(int i=2 ; i<=q ; i++){
            ll s_n = (a*s+b)%md;
            s = s_n;
            if(s_n & 1) {
                if(m[floor(s_n/2)] != true) m[floor(s_n/2)] = true,sum += floor(s_n/2);                    
            }else{
                if(m[floor(s_n/2)] == true){
                    sum -= floor(s_n/2);
                }else{
                    m[floor(s_n/2)] = false;
                }
            }
        }
        cout<<sum<<endl;
    }   
    return 0;
} 
