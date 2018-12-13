#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    int n = str.length();
    int cost = 0;
    char c = 'a';
    for(int i=0 ; i<n ; i++){
        cost += min(abs(str[i]-c),abs(26-abs(str[i]-c)));
        c = str[i];
    }
    cout<<cost<<endl;
    return 0;
}