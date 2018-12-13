#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        ll L,v,l,r;
        cin>>L>>v>>l>>r;
        ll a = (l-1)/v;
        ll b = r/v;
        cout<<(L/v) - (b-a)<<endl;
    }



    return 0;
}