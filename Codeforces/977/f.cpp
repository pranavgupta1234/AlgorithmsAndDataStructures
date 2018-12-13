#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;

    vector<ll> arr(n,0);
    map<ll,ll> m;
    
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    for(int i=0 ; i<n ; i++){
        m[arr[i]] = m[arr[i]-1]+1;
        if()
    }


    return 0;
}