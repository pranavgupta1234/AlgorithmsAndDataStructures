#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<ll> a(n, 0);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    sort(a.begin(), a.end());

    if(n == 2){
        cout<<0<<endl;
        exit(0);
    }

    cout<<min(a[n-1] - a[1], min(a[n-2] - a[0], a[n-1] - a[0]))<<endl;

    return 0;
}