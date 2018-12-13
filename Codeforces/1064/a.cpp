#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll ans = INT_MAX;

    ll a,b,c;
    cin>>a>>b>>c;
    ll arr[3] = { a, b, c};
    if(a + b > c and b + c > a and c + a > b) {
        cout<<0<<endl;
        exit(0);
    }
    sort(arr,arr+3);
    cout<<(arr[2] - arr[1] - arr[0] + 1)<<endl;

    return 0;
}