#include <bits/stdc++.h>
    
using namespace std;
    
typedef long long ll;
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        ll mat[n][n];
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> mat[i][j]; 
        ll mx = 0;
        int i = 0;
        for (int i = 0; i < n ; i++){
            int p = i, q = 0;
            ll tr = 0;
            while (p < n and q < n){
                tr += mat[p][q];
                p++, q++;
            }
            mx = max(mx, tr);
            p = 0, q = i;
            tr = 0;
            while (p < n and q < n){
                tr += mat[p][q];
                p++, q++;
            }
            mx = max(mx, tr);
        }
        cout << mx << endl;
    }
    return 0;
} 