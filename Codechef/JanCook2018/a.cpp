#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll s,n,k;
        cin>>n>>k>>s;
        if(s*k > ((s%7) + 6*(s/7))*n) cout<<"-1"<<endl;
        else cout<<((s*k)%n ? 1 : 0) + (s*k)/n<<endl;
    }
    return 0;
}