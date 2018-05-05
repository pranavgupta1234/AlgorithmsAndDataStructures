#include <bits/stdc++.h>

#define ll long long

using namespace std;

inline ll pwr(ll base,ll n,ll m){
    ll ans=1;
    while(n>0){
        if(n%2==1)ans=(ans*base)%m;
        base=(base*base)%m;
        n/=2;
    }
    return ans;
}

ll n,q;
ll bit[1000000];
ll arr[1000000];

void update(ll x,ll v){
    for(; x <= n ; x += (x&-x)) bit[x] += v;  
}

ll query(ll x){
    ll sum=0;
    for(; x>0 ; x -= (x&-x)) sum += bit[x];
    return sum;
}

bool search(ll val){        
    ll low = 1;
    ll high = n; 
    ll mid = low + (high-low)/2;
    ll v = query(mid);
    while(low < high){
        mid = low + (high-low)/2;
        v = query(mid);
        if(v == val) return true;
        else if(v < val) low = mid + 1;
        else high = mid - 1;
    }
    if(query(low) == val or query(high) == val) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll total = 0;
    for(int i=1 ; i<=n ; i++){
        cin>>arr[i];
        total += arr[i];
        update(i,arr[i]);
    }
    cin>>q;
    while(q--){
        int typ;
        cin>>typ;
        if(typ == 1){
            ll x,y;
            cin>>x>>y;
            total += y - arr[x];
            update(x,y-arr[x]);
            arr[x] = y;
        }else{
            ll z;
            cin>>z;
            if(total - z == 0 or search(total - z)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}