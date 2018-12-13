#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int t;
    cin>>t;
    
    while(t--){
        ll n,k,x,mn=INT_MAX,mx=INT_MIN,sum=0;
        cin>>n>>k>>x;
        vector<ll> p(k,0);
        for(int i=0 ; i<k ; i++) cin>>p[i],mn = min(mn,p[i]),mx=max(mx,p[i]);
        ll up = mn+x;
        ll from_last = n-k;
        ll lo = up - from_last;
        for(int i=0 ; i<k ; i++){
            if(p[i] > lo) from_last++;
        }
        sum += (up*(up+1)/2 - (up-from_last)*(up-from_last+1)/2);
        for(int i=0 ; i<k ; i++){
            sum += p[i]; 
            if(p[i] > lo) sum -= p[i];        
        }
        cout<<sum<<endl;
    }





    return 0;
}