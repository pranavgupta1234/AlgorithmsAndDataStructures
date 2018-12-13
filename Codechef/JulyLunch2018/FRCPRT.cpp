#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int mat[n][m];
        int rows[n];
        int cols[m];
        for(int i=0 ; i<n ; i++){
            string str;
            cin>>str;
            for(int j=0 ; j<m ; j++){
                mat[i][j] = str[j]-'0';
            } 
        }
        string mov;
        cin>>mov;
        for(int i=0 ; i<n ; i++){
            rows[i] = 0;
            for(int j=0 ; j<m ; j++){
                if(mat[i][j] == 1){
                    rows[i]++;
                }
            }
        }
        for(int j=0 ; j<m ; j++){
            cols[j] = 0;
            for(int i=0 ; i<n ; i++){
                if(mat[i][j] == 1){
                    cols[j]++;
                }
            }
        }
        int c1 = 0, c2 = 0;
        bool f = true;
        
        if(mov[0] == 'L' or mov[0] == 'R') f = true;
        else f = false;
        
        for(int i=0 ; i<mov.length() ; i++){
            if(mov[i] == 'L') c1 = 1;
            if(mov[i] == 'R') c1 = 2;
            if(mov[i] == 'U') c2 = 1;
            if(mov[i] == 'D') c2 = 2;
        }

        for(int i=0 ; i<n ; i++) for(int j=0 ; j<m ; j++) mat[i][j] = 0;

        if(c1 != 0 and c2 != 0){
            if(f){               
            // row fill
                for(int i=0 ; i<n ; i++){
                    int x = rows[i];
                    for(int j=0 ; j<m ; j++){
                        if(x > 0) mat[i][j] = 1,x--;
                        else mat[i][j] = 0;
                    }
                    if(c1 == 2){
                        reverse(mat[i],mat[i]+m);
                    }
                }
                for(int j=0 ; j<m ; j++){
                    cols[j] = 0;
                    for(int i=0 ; i<n ; i++){
                        if(mat[i][j] == 1){
                            cols[j]++;
                        }
                    }
                }
                // col fill
                for(int j=0 ; j<m ; j++){
                    int x = cols[j];
                    for(int i=0 ; i<n ; i++){
                        if(x > 0) mat[i][j] = 1,x--;
                        else mat[i][j] = 0;
                    }
                    if(c2 == 2) for(int i=0 ; i<n/2 ; i++) swap(mat[i][j],mat[n-i-1][j]);
                }
            }else{
                // col fill
                for(int j=0 ; j<m ; j++){
                    int x = cols[j];
                    for(int i=0 ; i<n ; i++){
                        if(x > 0) mat[i][j] = 1,x--;
                        else mat[i][j] = 0;
                    }
                    if(c2 == 2) for(int i=0 ; i<n/2 ; i++) swap(mat[i][j],mat[n-i-1][j]);
                }
                
                for(int i=0 ; i<n ; i++){
                    rows[i] = 0;
                    for(int j=0 ; j<m ; j++){
                        if(mat[i][j] == 1){
                            rows[i]++;
                        }
                    }
                }
                
                // row fill
                for(int i=0 ; i<n ; i++){
                    int x = rows[i];
                    for(int j=0 ; j<m ; j++){
                        if(x > 0) mat[i][j] = 1,x--;
                        else mat[i][j] = 0;
                    }
                    if(c1 == 2){
                        reverse(mat[i],mat[i]+m);
                    }
                }
            }
        } else if(c1 == 0 and c2 != 0){
            // col fill
            for(int j=0 ; j<m ; j++){
                int x = cols[j];
                for(int i=0 ; i<n ; i++){
                    if(x > 0) mat[i][j] = 1,x--;
                    else mat[i][j] = 0;
                }
                if(c2 == 2){
                    for(int i=0 ; i<n/2 ; i++) swap(mat[i][j],mat[n-i-1][j]);
                }
            }
        }else if(c1 != 0 and c2 == 0){
            // row fill
            for(int i=0 ; i<n ; i++){
                int x = rows[i];
                for(int j=0 ; j<m ; j++){
                    if(x > 0) mat[i][j] = 1,x--;
                    else mat[i][j] = 0;
                }
                if(c1 == 2){
                    reverse(mat[i],mat[i]+m);
                }
            }
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cout<<mat[i][j];
            }
            cout<<endl;
        }

    }
    return 0;
}