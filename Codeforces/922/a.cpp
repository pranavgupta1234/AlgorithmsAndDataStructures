#include <bits/stdc++.h>

#define ll long long
#define dll long double

using namespace std;

int x,y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>x>>y;
    if(y==0) cout<<"No"<<endl,exit(0);
    if(x == y) cout<<"No"<<endl;
    else if(x > y){
        if((x-y)&1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else{
        if(y-x == 1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}