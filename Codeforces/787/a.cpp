#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    for(int i=0 ; i<=max(max(a,b),max(c,d)) ; i++){
        for(int j=0 ; j<=max(max(a,b),max(c,d)) ; j++){
            if(b + a*i == d + c*j){
                cout<<a*i+b<<endl;
                exit(0);
            }
        }     
    }
    cout<<-1<<endl;
    return 0;
}