#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	char matrix[n][m];
	int dp[n+1][m+1];

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cin>>matrix[i][j];
		}
	}

	for(int i=0 ; i<=n ; i++){
		for(int j=0 ; j<=m ; j++){
			dp[i][j] = 0;
		}
	}

	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			if(matrix[i-1][j-1] == '0' and )
		}
	}

	return 0;
}