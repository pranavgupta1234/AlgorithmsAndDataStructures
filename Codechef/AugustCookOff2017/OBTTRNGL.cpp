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

inline bool isobt(ld a){
    if(a > 90 and a < 180) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll k,a,b;
        cin>>k>>a>>b;
        ld atc = abs(a-b)*360.0/k;
        ld opps = atc/2;
        ld slfs = 180.0 - opps;
        ll ans = 0;
        //cout<<atc<<" "<<opps<<" "<<slfs<<endl;
        if(!isobt(opps) and !isobt(slfs)) ans = 0;
        if(isobt(opps)) ans += k-(abs(a-b)+1);
        if(isobt(slfs)) ans += abs(a-b)-1;
        cout<<ans<<endl; 
    }

    return 0;
} 
