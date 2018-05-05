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
ll eea(ll a,ll b,ll &x,ll &y){ if(a == 0){x=0;y=1;return b;}ll x1, y1;ll d = eea(b%a, a, x1, y1);x=y1-(b/a)*x1;y=x1;return d;}
ll bsearch(ll a[],ll val,ll n){ll low = 1,high = n;while(low<=high){ll mid = low + (high-low)/2;if(a[mid] == val) return mid;else if(a[mid]<val) low = mid+1;else high = mid-1;}return -1;}

void update(ll x,ll val,ll bit[],ll n){
    for(;x<=n ; x+=(x&-x)) bit[x]+=val;
}

ll query(ll x,ll bit[]){
    ll sum = 0;
    for(; x>=0 ; x-=(x&-x)) sum += bit[x];
    return sum;
}

ll sum(ll l,ll r,ll bit[]){
    return query(r,bit)-query(r,bit);
}

void printm(map<ll,ll>& m){
    for(auto it = m.begin() ; it!=m.end() ; it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll w[n+1],c[n+1];
        for(int i=1 ; i<=n ; i++) cin>>c[i];
        for(int i=1 ; i<=n ; i++) cin>>w[i];
        map<ll,ll> m;
        ll ans=0,l=1,r=1,sum = 0;
        bool f = false;
        bool allu = true;
        while(r<=n){
            if(!f) r = l;
            if(m.find(c[r]) == m.end()) m[c[r]] = r,sum+=w[r],r++,f=true;
            else l = m[c[r]]+1,m.clear(),ans = max(ans,sum),sum=0,f = false,allu = false;
        }
        if(allu) cout<<sum<<endl;
        else cout<<ans<<endl;
    }    
    return 0;
} 
