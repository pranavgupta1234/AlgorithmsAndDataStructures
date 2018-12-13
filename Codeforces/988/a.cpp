#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    set<int> rat;
    map<int,int> r;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin>>t;
        rat.insert(t);
        r[t] = i+1; 
    }
    if(rat.size() < k) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        int l=0;
        for(int i : rat){
            if(l == k) break;
            cout<<r[i]<<" ";
            l++;
        }
        cout<<endl;
    }

    return 0;
}