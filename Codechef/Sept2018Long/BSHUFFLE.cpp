#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<int> mnp(n,0);
    vector<int> mxp(n,0);

    for(int i=0 ; i<n ; i++){
        if(i == 0) mnp[0] = n;
        else mnp[i] = i;
    }
    int c = 0;
    for(int i=2 ; i<=(n+1)/2 ; i++,c++){
        mxp[c] = i;
    }
    mxp[c++] = 1;
    for(int i=(n+1)/2+2; i <= n ; i++,c++) mxp[c] = i;
    mxp[c] = (n+1)/2 + 1;

    for(int i=0 ; i<n ; i++) cout<<mxp[i]<<" ";
    cout<<endl;
    for(int i=0 ; i<n ; i++) cout<<mnp[i]<<" ";
    cout<<endl; 
    return 0;
}