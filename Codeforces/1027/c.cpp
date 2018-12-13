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
        vector<int> h(11000,0);
        set<int> s;
        for(int i=0 ; i<n ; i++) cin>>a[i],h[a[i]]++;
        sort(a.begin(),a.end());
        auto it = unique(a.begin(),a.end());
        a.resize(distance(a.begin(),it));
        if(h[a[0]] >= 4) {
            cout<<a[0]<<" "<<a[0]<<" "<<a[0]<<" "<<a[0]<<endl;
        }else{
            cout<<a[0]<<" "<<a[0]<<" "<<a[1]<<" "<<a[1]<<endl;
        }
    }

    return 0;
}