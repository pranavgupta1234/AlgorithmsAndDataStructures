#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bsearch(vector<ll>& arr,ll k){
    ll n = arr.size();
    ll l=0,h=n-1;
    while(l<=h){
        ll m = l + (h-l)/2; 
        if(arr[m] == k) return m;
        else if(arr[m] > k){
            h = m-1;
        }else{
            l = m+1; 
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> pow2;
    ll n;
    for(int i=0 ; i<35 ; i++) pow2.push_back((ll)pow(2,i));
    cin>>n;
    vector<ll> arr(n,0);
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    set<ll> ans;
    for(ll a : arr){
        for(ll b : pow2){
            if(binary_search(arr.begin(),arr.end(),a+b)){
                cout<<a<<" ";
                ans.insert(a+b);
                ans.insert(a);
            }
        }
    }
    cout<<endl;
    cout<<ans.size()<<endl;
    for(ll a : ans) cout<<a<<" ";
    cout<<endl;
    return 0;
}