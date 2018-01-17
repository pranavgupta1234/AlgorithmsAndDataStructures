#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long 

using namespace std;

int a,b,c,n;
ll ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c>>n;
    for(int i=0 ; i<n ; i++){ll s;cin>>s; if(s>b and s<c) ans++;}
    cout<<ans<<endl;
    return 0;
}