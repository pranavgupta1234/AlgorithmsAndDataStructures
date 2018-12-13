#include <bits/stdc++.h>

using namespace std;

bool cust_compare(string a, string b){
    return a.length() < b.length();
}

bool cust_compare2(string a, string b){
    if(a.length() < b.length()) return -1;
    else if(a.length() == b.length()) return 0;
    else return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<string> str_arr(n);
    for(int i=0 ; i<n ; i++) cin>>str_arr[i];
    sort(str_arr.begin(),str_arr.end(),cust_compare);    
    for(int i=0 ; i<str_arr.size()-1 ; i++){
        if(str_arr[i+1].find(str_arr[i]) == string::npos) cout<<"NO"<<endl,exit(0); 
    }
    cout<<"YES"<<endl;
    for(int i=0 ; i<str_arr.size() ; i++){
        cout<<str_arr[i]<<endl;
    }
    return 0;
}