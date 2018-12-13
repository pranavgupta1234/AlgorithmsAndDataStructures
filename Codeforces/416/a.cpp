#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int l = -2*1e9,r = 2*1e9;
    bool f = false;
    for(int i=0 ; i<n ; i++){
        string a,b,c;
        cin>>a>>b>>c;
    
        if(a == ">"){
            if(c == "Y"){
                if(stoi(b)+1 > l) l = stoi(b)+1;
            }else{
                if(stoi(b) < r) r = stoi(b);
            }
        } 

        if(a == ">="){
            if(c == "Y"){
                if(stoi(b) > l) l = stoi(b);
            }else{
                if(stoi(b)-1 < r) r = stoi(b)-1;
            }
        } 
        if(a == "<"){
            if(c == "Y"){
                if(stoi(b)-1 < r) r = stoi(b)-1;
            }else{
                if(stoi(b) > l) l = stoi(b);
            }
        } 

        if(a == "<="){
            if(c == "Y"){
                if(stoi(b) < r) r = stoi(b);
            }else{
                if(stoi(b)+1 > l) l = stoi(b)+1;
            }
        }
    }

    if(l > r){
        cout<<"Impossible"<<endl;
    }else{
        cout<<l<<endl;
    }

    return 0;
}