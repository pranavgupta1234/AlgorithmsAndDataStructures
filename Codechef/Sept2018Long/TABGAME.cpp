#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        string M,N;
        cin>>M>>N;
        int n = N.length();
        int m = M.length();
        char mat[n+1][m+1];
        vector<int> mn(n+1,0);
        vector<int> mm(m+1,0);
        int c = 0;
        if(N[0] == '0' or M[0] == '0') c = 0;
        else c = 1;
        for(int i=1 ; i<=n ; i++){
            if(N[i-1] == '0') {
                c = 0;
            }
            mn[i] = c;
            c++;
        }
        if(M[0] == '0' or N[0] == '0') c = 0;
        else c = 1;
        for(int i=1 ; i<=m ; i++){
            if(M[i-1] == '0') {
                c = 0;
            }
            mm[i] = c;
            c++;
        }
        for(int i=1 ; i<=n ; i++){
            if(N[i-1] == '0') mat[i][1] = 'A'; 
            else if(mn[i] & 1) mat[i][1] = 'B';
            else mat[i][1] = 'A';
        }
        for(int i=1 ; i<=m ; i++){
            if(M[i-1] == '0') mat[1][i] = 'A'; 
            else if(mm[i]&1) mat[1][i] = 'B';
            else mat[1][i] = 'A';
        }
        if(M[0] == '0' or N[0] == '0') mat[1][1] = 'A';
        else mat[1][1] = 'B'; 
        for(int i=2 ; i<=n ; i++){
            for(int j=2 ; j<=m ; j++){
                if(mat[i-1][j] == 'A' and mat[i][j-1] == 'A') mat[i][j] = 'B';
                else mat[i][j] = 'A';
            }
        }
        /*
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        int q;
        cin>>q;
        while(q--){
            int x,y;
            cin>>x>>y;   
            if(mat[x][y] == 'A') cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }

    return 0;
}