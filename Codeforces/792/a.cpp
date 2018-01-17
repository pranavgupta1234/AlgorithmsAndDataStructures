#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int n;
int arr[200500];
map<ll,ll> m;
int mdiff = INT_MAX;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    sort(arr,arr+n);
    m.clear();
    for(int i=1 ; i<n ; i++){
        mdiff = min(mdiff,abs(arr[i]-arr[i-1]));
        m[abs(arr[i]-arr[i-1])]++;
    }
    cout<<mdiff<<" "<<m[mdiff]<<endl;
    return 0;
}
