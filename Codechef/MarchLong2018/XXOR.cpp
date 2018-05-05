#include <bits/stdc++.h>
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
    int n,q;
    cin>>n>>q;
    ll a[n+1];
    vector<string> bits;
    vector<vector<int> > dp(n+1,vector<int>(65,0));
    for(int i=1 ; i<=n ; i++){
        cin>>a[i];
        bits.push_back(bitset<64>(a[i]).to_string());
    }
    for(int i=1 ; i<=64 ; i++){
        dp[1][i] = bits[0][i-1]-'0';
    }  
    for(int i=2 ; i<=n ; i++){
        for(int j=1 ; j<=64 ; j++){
            dp[i][j] += (bits[i-1][j-1]-'0') + dp[i-1][j];
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        string xxor="";
        for(int i=34 ; i<=64 ; i++){
            if((r-l)&1){
                if(dp[r][i]-dp[l-1][i] < (r-l+1)/2) xxor += "1";
                else xxor += "0";
            }else{
                if(dp[r][i]-dp[l-1][i] <= (r-l)/2) xxor += "1";
                else xxor += "0";
            }
        }

        cout<<bitset<31>(xxor).to_ulong()<<endl;
    }
    return 0;
} 
