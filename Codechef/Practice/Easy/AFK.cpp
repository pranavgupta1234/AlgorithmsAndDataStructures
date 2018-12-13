#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if((a+c) & 1) cout<<max(abs((a+c+1)/2-b),abs((a+c-1)/2-b))<<endl; 
        else cout<<abs((a+c)/2-b)<<endl;
    }

    return 0;
}