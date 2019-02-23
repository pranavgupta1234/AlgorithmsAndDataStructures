#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin>>str;

    string ans = "";
    int n = str.length();

    int i = (n-1)/2;
    int j=i+1;
    
    while(i>=0 or j<n){
        if(i >= 0) ans += str[i];
        if(j < n)  ans += str[j];
        i--;
        j++;
    }

    cout<<ans<<endl;

    return 0;
}