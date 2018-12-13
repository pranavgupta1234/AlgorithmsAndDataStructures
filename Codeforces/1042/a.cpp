#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> a(n,0);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    int mx = INT_MIN;
    ll g = 0;
    for(int i=0 ; i<n ; i++) mx = max(mx,a[i]);
    for(int i=0 ; i<n ; i++){
        g += abs(a[i]-mx);
    }
    if(g >= m and g != 0) cout<<mx<<" "<<mx+m<<endl;
    else{
        int r = m - g;
        cout<<mx+(r/n)+(r % n == 0 ? 0 : 1)<<" "<<mx+m<<endl;
    }

    return 0;
}