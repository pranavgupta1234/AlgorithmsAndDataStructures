#include <bits/stdc++.h>

using namespace std;

int n,m,k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mind = INT_MAX;
    cin>>n>>m>>k;
    for(int i=1 ; i<=n ; i++){int a;cin>>a;if(a <= k and a != 0)mind = min(mind,abs(m-i));}
    cout<<10*mind<<endl;
    return 0;
}