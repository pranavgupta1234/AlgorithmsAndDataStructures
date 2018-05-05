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
ll bsearch(ll a[],ll val,ll n){
    ll low = 1,high = n;
    while(low<=high){
        ll mid = low + (high-low)/2;
        if(a[mid] == val) return mid;
        else if(a[mid]<val) low = mid+1;
        else high = mid-1;
    }
    return -1;  //not found
}

ll arr[120];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,d;
    cin>>n>>d;
    set<int> s;
    for(int i=1 ; i<=n ; i++) cin>>arr[i],s.insert(arr[i]);
    int c =0;
    for(int i=1 ; i<=n ; i++) if(arr[i] == *s.begin()) c++;
    sort(arr+1,arr+n+1);
    int ans = arr[n]-arr[1];
    for(int i=1 ; i<=n ; i++){
        for(int j=i ; j<=n ; j++){
            if(arr[j] - arr[i] > d){
                ans = min(ans,n-(j-i));
                break;
            }  
        }
    }
    if(n == 1) cout<<0<<endl;
    else if(s.size() > 1) cout<<(n-c)<<endl;
    else if(arr[n] - arr[1] <= d) cout<<0<<endl;
    else if(arr[2] - arr[1] > d) cout<<n-1<<endl; 
    else cout<<ans<<endl;
    return 0;
} 