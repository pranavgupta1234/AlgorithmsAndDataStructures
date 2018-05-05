#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int c = 0;
    int i=0,j=s.length()-1;
    while(i <= j){if(s[i] != s[j]){c++;if(c > 1){break;}}i++,j--;}   
    cout<<(c == 1 or (s.length()&1 and c == 0)  ? "YES" : "NO")<<endl;
    return 0;
}