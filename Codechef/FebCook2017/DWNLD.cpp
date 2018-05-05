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
        int n,k;
        cin>>n>>k;
        int t[n+1],d[n+1];
        for(int i=1 ; i<=n ; i++)   cin>>t[i]>>d[i];
        ll pay = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=t[i] ; j++){
                k--;
                if(k < 0) pay += d[i];
            }
        }
        cout<<pay<<endl;
    }   
    return 0;
} 
