#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n,s;

bool check(ll val){
    ll dsum = 0;
    ll cval = val;
    while(val>0){
        dsum += val%10;
        val /= 10;
    }
    return cval - dsum >= s ? true : false;
}

ll search(ll low,ll high){
    while(low < high){
        ll mid = low + (high-low)/2;
        if(check(mid))  high = mid;
        else  low = mid+1;
    }
    if(check(low) == false) return -1;
    else return low;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    ll ans = search(1,n);
    if(ans == -1) cout<<0<<endl, exit(0);
    cout<<n-ans+1<<endl;
    return 0;
}