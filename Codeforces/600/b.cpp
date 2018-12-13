#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> a(n,0);
    vector<int> b(m,0);

    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<m ; i++) cin>>b[i];

    sort(a.begin(),a.end());

    for(int i=0 ; i<m ; i++){
        auto p = upper_bound(a.begin(),a.end(), b[i]);
        if(p == a.end()) cout<<n<<" ";
        else cout<<p - a.begin()<<" ";
    }
    cout<<endl;
    return 0;
}