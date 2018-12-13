#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin>>n;
    string str;
    cin>>str;
    int h[26] = {0};
        for(int i=0 ; i<n ; i++) h[str[i]-'0']++;
    string ans = "";
    for(int i=0 ; i<26 ; i++){
        if(h[i] == 0) continue;
        if(h[i] % 2 == 0){
            int c = h[i];
            char x = 'a'+i;
            string s1(c/2, x);
            string s2(c/2, x);

        }
    }

    return 0;
}