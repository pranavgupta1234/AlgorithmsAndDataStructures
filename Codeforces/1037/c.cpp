#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    ll cost = 0;
    for(int i=0 ; i<n ; i++){
        if(a[i] == b[i]) continue;
        if(i+1 < n and a[i+1] != b[i]) cost++;
        else{
            if(i+1 < n and a[i+1] == b[i] and b[i+1] == a[i]) swap(a[i],a[i+1]);
            cost++;
        }
    }
    cout<<cost<<endl;
    return 0;
}