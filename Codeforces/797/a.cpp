#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int n,k;
vector<int> fac;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    int cpyn = n;
    for(int i=2 ; i<=n ; i++){
        while(n%i == 0){
            fac.push_back(i);
            n /= i;
        }   
    }
    ll a = 1;
    if(fac.size() < k)  cout<<-1<<endl, exit(0);
    else for(int i=0 ; i<k-1 ; i++) cout<<fac[i]<<" ", a*=fac[i] ;
    cout<<cpyn/a<<endl;
    return 0;
}