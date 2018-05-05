#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    string cp = s;
    reverse(cp.begin(),cp.end());
    s += cp;
    cout<<s<<endl;
    return 0;
}