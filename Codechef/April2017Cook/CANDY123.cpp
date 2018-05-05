#include <bits/stdc++.h>

#define ll long long 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        ll ta=1,tb=2;
        bool f = false;
        int oddc = 2;
        while(!f){
            if(ta > a) cout<<"Bob"<<endl,f = true;
            else if(tb > b) cout<<"Limak"<<endl,f = true;
            else ta += 2*oddc-1,tb += 2*oddc;
            //cout<<ta<<" "<<tb<<endl;
            oddc++;
        }
    }


    return 0;
}