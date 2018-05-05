#include <bits/stdc++.h>

#define dll double long
#define ll long long

using namespace std;

int n;
string s;
string ans;

inline bool isvowel(int i){
    if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'y') return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    cin>>s;
    for(int i=0 ; i<s.length() ; ){
        if(isvowel(i)){
            ans += s[i];
            while(isvowel(i)) i++;
            continue;
        } 
        ans += s[i];
        i++;
    }
    cout<<ans<<endl;
    return 0;
}