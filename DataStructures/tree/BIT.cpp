#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll n;
ll arr[1000000];
ll bit[10000000];

void update(int x,int val){
    for(; x<=n ; x += x&-x) bit[x] += val;
}

ll query(int x){
    ll sum = 0;
    for(; x>0 ; x-= x&-x) sum += bit[x];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        cin>>arr[i];
        update(i,arr[i]);
    }
    cout<<query(10)-query(2)<<endl;
    return 0;
}