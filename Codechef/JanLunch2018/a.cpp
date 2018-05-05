#include <bits/stdc++.h>

#define ll long long
#define dll long double

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int odd=0,even=0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            if(arr[i] & 1) odd++;
            else even++;
        }
        if(odd & 1) cout<<2<<endl;
        else cout<<1<<endl;
    }
    return 0;
}