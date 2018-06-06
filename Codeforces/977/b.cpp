#include <bits/stdc++.h>

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    map<string,int> s;
    string str;
    cin>>str;
    for(int i=0 ; i<str.length()-1 ; i++){
        string temp = "";
        temp += str[i];
        temp += str[i+1];
        s[temp]++;
    }
    int mx = -1;
    string ans = "";
    for(auto &it : s){
        if(it.second > mx){
            mx = it.second;
            ans = it.first;
        }
    }
    cout<<ans<<endl;
}