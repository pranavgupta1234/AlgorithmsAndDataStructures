#include <bits/stdc++.h>

#define ll long long
#define dll long double

using namespace std;

ll n;
vector<ll> fib;
char name[20000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll a=1,b=1;
    int i=0;
    fib.push_back(1);
    while(fib[i++] <= 1500){
        ll t = a + b;
        a = b;
        b = t;
        fib.push_back(t);
    }
    for(int i=1 ; i<=n ; i++) name[i] = 'o';
    for(int i=0 ; i<fib.size() ; i++){
        name[fib[i]] = 'O';
    }
    for(int i=1 ; i<=n ; i++) cout<<name[i];
    cout<<endl;
    return 0;
}