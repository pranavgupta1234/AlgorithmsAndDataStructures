#include <bits/stdc++.h>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    vector<int> pref(n,0);
    pref[0] = a[0];
    for(int i=1 ; i<n ; i++) pref[i] = pref[i-1] + a[i];

    sort(pref.begin(),pref.end());



    return 0;
}