#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,s;
    cin>>n>>s;
    vector<ll> a(n,0);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll cost = abs(a[n/2] - s);   
    int i = n/2 - 1;
    int j = n/2 + 1;
    while(i>=0 and j<n){
        if(a[i] > s) cost += abs(a[i]-s);
        if(a[j] < s) cost += abs(a[j]-s);
        if(a[i] < s and a[j] > s) break;
        i--;
        j++;
    }
    cout<<cost<<endl;
    return 0;
}