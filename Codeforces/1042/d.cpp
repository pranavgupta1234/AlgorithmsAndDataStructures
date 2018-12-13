#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
    
ll n,t;
ll arr[200100];
ll pref[200100];
ll ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>t;

    for(int i=1 ; i<=n ; i++) cin>>arr[i];
    for(int i=1 ; i<=n ; i++) pref[i] = arr[i] + pref[i-1];

    int i=1,j=1;

    while(i < n){
        while(j < n and pref[j] - pref[i-1] < t){
            ans++;
            j++;
        }
        
    }


    return 0;
}

