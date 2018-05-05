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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> ord(n);
        bool f = true;
        for(int i=0 ; i<n ; i++) cin>>ord[i];
        for(int i=0 ; i<n-1 ; i++){
            if(ord[i] == "cookie" and ord[i+1] != "milk") { f = false;cout<<"NO"<<endl ; break; }
        }
        if(f) if(ord[n-1] == "cookie") f = false,cout<<"NO"<<endl;
        if(f) cout<<"YES"<<endl;
    }
    return 0;
} 
