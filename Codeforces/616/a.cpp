#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a,b;
    cin>>a>>b;
    
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int i=a.length()-1;
    while(a[i] == '0'){
        a.pop_back();
        i--;
    }
    i = b.length()-1;
    while(b[i] == '0'){
        b.pop_back();
        i--;
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    if(a == b) cout<<"="<<endl,exit(0);
    if(a.length() > b.length()){
        cout<<">"<<endl;
    }else if(a.length() < b.length()){
        cout<<"<"<<endl;
    }else{
        for(int i=0 ; i<a.length() ; i++){
            if(a[i] > b[i]) cout<<">"<<endl,exit(0);
            else if(a[i] < b[i]) cout<<"<"<<endl,exit(0);
            else continue;
        }
    }
    return 0;
}