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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int u=0,d=0;
        for(int i=0 ; i<s.length() ;){  
            char c = s[i];
            int j = i;
            while(s[j] == c and j<s.length()){
                j++;
                i++;
            }
            if(c == 'U') u++;
            else d++;
        }
        cout<<min(u,d)<<endl;
    }   
    return 0;
} 
