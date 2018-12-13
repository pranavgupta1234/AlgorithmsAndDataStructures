#include <bits/stdc++.h>

using namespace std;

char mat[18][18];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=0 ; i<8 ; i++) for(int j=0 ; j<8 ; j++) cin>>mat[i][j];
    int ans = 0;
    for(int i=0 ; i<8 ; i++){
        int c = 0;
        for(int j=0 ; j<8 ; j++){
            if(mat[i][j] == 'B') c++;
        }
        if(c == 8) ans++;
    }
    for(int i=0 ; i<8 ; i++){
        int c = 0;
        for(int j=0 ; j<8 ; j++){
            if(mat[j][i] == 'B') c++;
        }
        if(c == 8) ans++;
    }
    if(ans == 16) cout<<ans/2<<endl;
    else cout<<ans<<endl;
    return 0;
}