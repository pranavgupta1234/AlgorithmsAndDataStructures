#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int bsearch(int arr[],int l,int h,int val){
    while(l<=h){
        int m = l + (h-l)/2;
        if(arr[m] == val) return m;
        else if(arr[m] < val) h = m-1;
        else l = m+1; 
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    ll arr[n+1];
    for(int i=1 ; i<=n ; i++) cin>>arr[i];
    while(q--){
        int typ;
        cin>>typ;
        if(typ == 1){
            int x,y;
            cin>>x>>y;
            arr[x] = y;
        }else{
            int l,r;
            cin>>l>>r;
            ll ans = -1;
            ll carr[r-l+1];
            for(int i=0 ; i<r-l+1 ; i++){
                carr[i] = arr[l+i];   
            }
            sort(carr,carr+r-l+1,greater<int>());
            for(int i=0 ; i<r-l-1 ; i++){
                if(carr[i] < carr[i+1] + carr[i+2]){
                    ans = carr[i] + carr[i+1] + carr[i+2];
                    break;
                } 
            }
            if(ans == -1) cout<<0<<endl;
            else cout<<ans<<endl;
        }
    }
    return 0;
} 
