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
        ll n,a,b,c;
        cin>>n>>a>>b>>c;
        ll mx = max(a,max(b,c));
        set<ll> divi;
        vector<ll> d;
        ll ans = 0;
        for(int i=1 ; i*i<=n ; i++){
            if(n % i == 0){
                if(i < mx) divi.insert(i);
                if(n/i < mx) divi.insert(n/i);
            } 
        }
        for(auto it = divi.begin() ; it != divi.end() ; it++) d.push_back(*it);
        for(int i=0 ; i<d.size() ; i++){
            for(int j=0 ; j<d.size() ; j++){
                ll num = n/(d[i]*d[j]);
                if(d[i] <= a  and d[j] <= b and num <= c and d[i]*d[j]*num == n){
                    //cout<<d[i]<<" "<<d[j]<<" "<<n/(d[i]*d[j])<<endl;
                    ans++;
                } 
            }
        }
        cout<<ans<<endl;
    }
    return 0;
} 
