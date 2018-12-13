#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> a(n+1,0);
        for(int i=1 ; i<=n ; i++) cin>>a[i];
        while(q--){
            int l,r;
            cin>>l>>r;
            int cnt = 0;
            for(int i=l ; i<=r ; i++){
                int x = a[i];
                for(int j=i ; j <=r ; j++){
                    x = x & a[j];
                    if(floor(sqrt(x)) == sqrt(x)) cnt++; 
                }
            }
            cout<<cnt<<endl;
        }
    }

    return 0;
}