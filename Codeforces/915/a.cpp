#include <bits/stdc++.h>

#define ll long long 
#define ull unsigned long long
using namespace std;

int gcd(int a,int b){
    if(a==0) return b;
    else return gcd(b%a,a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll m = 10000000000;
    for(int i=0 ; i<n ; i++){
        int x;
        cin>>x;
        if(k%x == 0){
            m = min(m,k/x);
        }
    }

    cout<<m<<endl;
    return 0;
}