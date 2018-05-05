#include <bits/stdc++.h>

using namespace std;

int n;
int o,t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);              
    cin>>n;
    for(int i=0 ; i<n ; i++){
        int v;
        cin>>v;
        if(v == 1) o++;
        else t++;
    }
    if(o == 0) cout<<0<<endl;
    else if(t >= o) cout<<o<<endl;
    else cout<<t+(o-t)/3<<endl;
    return 0;
}
