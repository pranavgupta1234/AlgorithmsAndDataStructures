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
        map<string,int> m;
        for(int i=1 ; i<=4 ; i++){
            string team;
            int sc;
            cin>>team>>sc;
            m[team] = sc;
        }   
        if(m["RealMadrid"] < m["Malaga"] and m["Barcelona"] > m["Eibar"]) cout<<"Barcelona"<<endl;
        else cout<<"RealMadrid"<<endl;
    }   
    return 0;
} 
