#include <bits/stdc++.h>

#define ll long long 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll a=0,b=0,mx=0;
        for(int i=1 ; i<=n ; i++){
            if(s[i-1] == 'a') a++;
            if(s[i-1] == 'b') mx+=a,b++;
        }
        mx = mx*k;
        mx += (k*(k-1)*a*b)/2;
        cout<<mx<<endl;
    }
    return 0;
}