#include <bits/stdc++.h>

using namespace std;

int n,h;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed;
    cout<<setprecision(12);
    cin>>n>>h;
    for(int i=1 ; i<=n-1 ; i++) { cout<<(sqrt(i)*h*1.0/sqrt(n))<<" ";}
    cout<<endl;
    return 0;
}