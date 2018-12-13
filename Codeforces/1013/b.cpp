#include <bits/stdc++.h>

using namespace std;

int f1[200500], f2[200500], ans = -1, n, x, y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>x;
    for(int i=1 ; i<=n ; i++){
        cin>>y;
        if(f1[y]) ans = 0;
        if(ans) if(f1[y&x] or f2[y]) ans = 1;
        if(ans != 0 and ans != 1) if(f2[y&x]) ans = 2;
        f1[y] = 1;
        f2[y&x] = 1;
    }
    cout<<ans<<endl;
    return 0;
}