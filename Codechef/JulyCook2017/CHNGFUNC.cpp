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
ll pwrmod(ll a,ll b){ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll pwr(ll a,ll b){ll res=1;assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} 

ll poss(ll val,ll a,ll b){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll m,n;
    cin>>n>>m;
    ll p,i;
    ll count=0;
    for(i=1;i<=n;i++){
        p=i+1;
        while((p*p-i*i)<=m){
            p++;
            count++;
        }
 
    }
    cout<<count<<endl;
    return 0;
} 
