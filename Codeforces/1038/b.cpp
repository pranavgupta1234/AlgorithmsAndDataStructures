#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin>>n;

    if(n == 1 or n==2) cout<<"No"<<endl,exit(0);

    if(n*(n+1)/2 & 1){
        cout<<"Yes"<<endl;
        cout<<1<<" "<<n<<endl;
        cout<<n-1<<" ";
        for(int i=1 ; i<=n-1 ; i++) cout<<i<<" ";
        cout<<endl;
    }else{
        cout<<"Yes"<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<n-1<<" ";
        for(int i=1 ; i<=n ; i++){
            if(i != 2) cout<<i<<" ";
        }
        cout<<endl;
    }


    return 0;
}