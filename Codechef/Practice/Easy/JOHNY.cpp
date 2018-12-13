#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n,0);
        for(int i=0 ; i<n ; i++) cin>>a[i];
        int k;
        cin>>k;
        int f = a[k-1];
        sort(a.begin(),a.end());
        for(int i=0 ; i<n ; i++){
            if(a[i] == f){
                cout<<i+1<<endl;
                break;
            }
        }
    }   
    return 0;
}