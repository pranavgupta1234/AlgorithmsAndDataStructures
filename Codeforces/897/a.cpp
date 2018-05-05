#include <bits/stdc++.h>

using namespace std;

int n,m;
string org;
int l,r;
char c1,c2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    cin>>org;
    for(int i=1 ; i<=m ; i++){
        cin>>l>>r>>c1>>c2;
        for(int i=l-1 ; i<=r-1 ; i++) if(org[i] == c1) org[i] = c2;
    }
    cout<<org<<endl;
    return 0;
}