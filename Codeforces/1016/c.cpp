#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mat[2][300100];
ll dp[2][300100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;    

    for(int i=0 ; i<n ; i++) cin>>mat[0][i];
    for(int i=0 ; i<n ; i++) cin>>mat[1][i];    

    dp[0][0] = mat[0][0];

    
    


    return 0;
}
