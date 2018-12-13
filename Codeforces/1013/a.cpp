#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll sum = 0; 
    for(int i=0 ; i<n ; i++){
        int t;
        cin>>t;
        sum += t;
    }
    for(int i=0 ; i<n ; i++) {
        int t;
        cin>>t;
        sum -= t;
    }

    if(sum >= 0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    return 0;
}