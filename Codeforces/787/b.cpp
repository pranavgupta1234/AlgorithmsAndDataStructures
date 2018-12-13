#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    bool ans = true;
    for(int i=0 ; i<m ; i++){
        int k;
        cin>>k;
        vector<int> a(k,0);
        for(int j=0 ; j<k ; j++) cin>>a[j];
        sort(a.begin(),a.end());
        bool f = false;
        for(int j=0 ; j<k ; j++){
            if(binary_search(a.begin(),a.end(),(-1)*a[j])) {
                f = true;
                break;
            } 
        }
        ans = ans & f;
    }
    if(!ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}