#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<l<<" "<<r-(r%l)<<endl;
    }

    return 0;
}