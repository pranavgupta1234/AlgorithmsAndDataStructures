#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define m 998244353


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll n;
    cin>>n;

    string str;
    cin>>str;

    ll ans = 1;

    if(n == 1) cout<<1<<endl, exit(0);
    if(n == 2) cout<<3<<endl, exit(0);

    set<char> s(str.begin(), str.end());

    if(s.size() == 1) {
        ans = (((n%m)*(n%m+1))%m)/2;
        ans = ans%m;
        cout<<ans<<endl;
        exit(0);
    }

    ll i=1;
    ll l=1,r=1;
    while(str[i] == str[0]){
        i++,l++;
    }
    i=n-2;
    while(str[i] == str[n-1]){
        i--,r++;
    }
    ans +=  (l%m + r%m)%m;
    if(str[0] == str[n-1]){
        ans += ((l%m)*(r%m))%m;
    }
    cout<<ans%m<<endl;

    return 0;
}