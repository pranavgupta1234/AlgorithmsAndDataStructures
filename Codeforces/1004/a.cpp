#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,d;
    cin>>n>>d;

    ll ans = 2;
    vector<int> a(n,0);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    for(int i=0 ; i<n-1 ; i++){
        if(a[i+1] - a[i] == 2*d) ans++;
        if(a[i+1] - a[i] > 2*d) ans += 2;  
    }

    cout<<ans<<endl;




    return 0;
}