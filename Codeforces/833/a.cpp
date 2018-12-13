#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    for(int i=0 ; i<n ; i++){
        ll a,b;
        cin>>a>>b;
        ll mul = a*b;
        long double c = cbrt(mul);
        cout<<c<<endl;
        if((ll)c == c and a%(ll)c == 0 and b%(ll)c == 0) cout<<"Yes"<<endl; 
        else cout<<"No"<<endl;
    }
    return 0;
}