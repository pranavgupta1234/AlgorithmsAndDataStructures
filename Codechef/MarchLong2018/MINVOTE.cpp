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

inline bool ok(ll csum[],ll arr[],int b,int end){
    if(abs(csum[end-1]-csum[b]) > arr[b]) return true;
    else return false;
}

inline bool ok2(ll csum[],ll arr[],int b,int end){
    if(abs(csum[b-1]-csum[end]) <= arr[b]) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll arr[n+1];
        ll ans[n+2];
        ll csum[n+1];
        for(int i=1 ; i<=n ; i++) cin>>arr[i];
        for(int i=0 ; i<=n ; i++) ans[i] = 0;
        arr[0] = 0,csum[0] = 0,csum[1] = arr[1],arr[n+1] = LONG_LONG_MAX;        
        for(int i=2 ; i<=n ; i++) csum[i] = arr[i] + csum[i-1];
        for(int i=1 ; i<=n ; i++){
            int l=i,h=n+1;
            while(l<h){
                int mid = l + (h-l)/2;
                if(ok(csum,arr,i,mid)){
                    h = mid;
                }else{
                    l = mid+1;
                }
            }
            if(i<l){
                ans[i+1]++;
                ans[l]--;
            }
            l=1,h=i;
            while(l<h){
                int mid = l + (h-l)/2;
                if(ok2(csum,arr,i,mid)){
                    h = mid;
                }else{
                    l = mid+1;
                }
            }
            if(l<i){
                ans[l]++,ans[i]--;
            }
        }
        for(int i=1 ; i<=n ; i++) ans[i] += ans[i-1];        
        for(int i=1 ; i<=n ; i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
} 
