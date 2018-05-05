#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const ll mod=1000000007;
ll pwrmod(ll a,ll b){ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll pwr(ll a,ll b){ll res=1;assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k,b;
        cin>>n>>k>>b;
        vector<ll> a(n+1,0);
        for(int i=0 ; i<n ; i++) cin>>a[i];
        a[n] = LONG_LONG_MAX;
        sort(a.begin(),a.end());
        ll ans = 0;
        ll curr = a[n-1];
        while(binary_search(a.begin(),a.end(),curr)){ 
            auto it = lower_bound(a.begin(),a.end(),(curr-b)/k);
            it--;
            curr = *it;
            cout<<curr<<endl; 
            ans++;
        }      
        if(k == 0 and b == 0) cout<<n<<endl;  
        else cout<<ans<<endl;
    }
    return 0;
} 
