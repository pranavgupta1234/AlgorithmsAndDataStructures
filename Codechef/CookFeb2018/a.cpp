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

        int n;
        cin>>n;
        int arr[n][5];
        for(int i=0 ; i<n ; i++){
            ll sum = 0;
            for(int j=0 ; j<5 ; j++){
                cin>>arr[i][j];
                sum += arr[i][j];
            }
            if(sum == 0) cout<<"Beginner"<<endl;
            else if(sum == 1) cout<<"Junior Developer"<<endl;
            else if(sum == 2) cout<<"Middle Developer"<<endl;
            else if(sum == 3) cout<<"Senior Developer"<<endl;
            else if(sum == 4) cout<<"Hacker"<<endl;
            else cout<<"Jeff Dean"<<endl;
        

    }
    return 0;
} 
