#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[10][1000002];

int f(int x){
	if(x<10)return x;
	int prod=1;
	while(x){
		if(x%10)prod*=(x%10);
		x/=10;
	}
	return f(prod);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin>>q;
    for(int i=1 ; i<=1000000 ; i++){
        dp[f(i)][i]++;
    }
    for(int i=1 ; i<=9 ; i++){
        for(int j=1 ; j<=1000000 ; j++){
            dp[i][j] += dp[i][j-1];
        }
    }
    while(q--){
        ll l,r,k;
        cin>>l>>r>>k;
        cout<<dp[k][r]-dp[k][l-1]<<endl;
    }
    return 0;
}
