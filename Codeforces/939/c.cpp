#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=1000000007;
ll pwrmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll pwr(ll a,ll b){ll res=1;assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} 

ll n;
ll a[300100];
ll idx[300000];
ll cum[300000];
ll s,f;
ll sum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        cin>>a[i];
        a[i+n] = a[i];
    }
    cum[1] = a[1];
    for(int i=2 ; i<=2*n ; i++) cum[i] += a[i] + cum[i-1]; 
    cin>>s>>f;
    for(int i=s ; i<f ; i++) sum += a[i];
    for(int i=1 ; i<=n ; i++){
        idx[i] = i;
        idx[i+n] = i;
    }
    ll l = n + s,r = n + f - 1;
    ll init_s = sum;
    ll t = 1;
    ll anst = 1;
    while(l != s){
        l--,r--,t++;
        sum = cum[r] - cum[l-1];
        if(sum > init_s){
            anst = t;
            init_s = sum;
        }
    } 
    cout<<anst<<endl;
    return 0;
}