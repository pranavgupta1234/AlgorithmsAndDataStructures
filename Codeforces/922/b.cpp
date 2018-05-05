#include <bits/stdc++.h>

#define ll long long
#define dll long double

using namespace std;

int n;
ll ct;
map<ll,bool> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1 ; i<=n ; i++) m[i] = false;
    for(ll a=1 ; a<=n ; a++){
        for(ll b=a ; b<=n ; b++){
            ll c = a^b;      
            if((c >= b) and (c <= n) and  (a+b > c) and (b+c > a) and (a+c > b) and (m[a] == false or m[b] == false or m[c] == false)){
                m[a] = true;
                m[b] = true;
                m[c] = true;
                ct++;
                cout<<a<<" "<<b<<" "<<c<<endl;
            }
        }
    }
    cout<<ct<<endl;
    return 0;
}