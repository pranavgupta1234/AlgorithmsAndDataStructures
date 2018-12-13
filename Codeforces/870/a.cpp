#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,t;
    cin>>n>>m;
    set<int> a,b;
    int s1 = 100,s2 = 100;
    for(int i=0 ; i<n ; i++) cin>>t, s1 = min(s1,t), a.insert(t);    
    for(int i=0 ; i<m ; i++) cin>>t, s2 = min(s2,t), b.insert(t);
    for(auto  i : b) if(a.find(i) != a.end()) cout<<i<<endl,exit(0);
    cout<<min(s1,s2)<<max(s1,s2)<<endl;
    return 0;
}