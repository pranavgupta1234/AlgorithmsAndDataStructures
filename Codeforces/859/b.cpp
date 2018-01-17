#include <bits/stdc++.h>
using namespace std;
int n;
int rootn;
int main(){
    cin>>n;
    rootn = floor(sqrt(n));
    cout<<4*rootn+2*ceil((n - rootn*rootn)*1.0/rootn)<<endl;
    return 0;
}