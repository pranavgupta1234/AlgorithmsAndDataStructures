#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin>>n;
    vector<int> a(n,0);
    vector<int> b(n,0);
    set<int> s;
    ll cnt = 0;
    for(int i=0 ; i<n ; i++) cin>>a[i],s.insert(a[i]);
    for(int i=0 ; i<n ; i++) cin>>b[i],s.insert(b[i]);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(s.find(a[i] ^ b[j]) != s.end()) cnt++;
        }
    }
    if(cnt & 1) cout<<"Koyomi"<<endl;
    else cout<<"Karen"<<endl;
    return 0;
}