#include <bits/stdc++.h>

using namespace std;

int powerx(int num,int x){
	int p = 0;
	while(num % x == 0){
		p++;
		num = num/x;
	}
	return p;
}

int main(){
	int n;
	cin>>n;
	vector<char> path;
	pair<int,int> fac[n][n];
	int dp[n+1][n+1];

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			int num;
			cin>>num;
			fac[i][j].first = powerx(num,2);
			fac[i][j].second = powerx(num,5);
		}
	}

	for(int i=0 ; i<= n ; i++){
		for(int j=0 ; j<=n ; j++){
			dp[i][0] = 0;
			dp[0][i] = 0;
		}
	}

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			cout<<fac[i][j].first<<","<<fac[i][j].second<<" ";
		}
		cout<<endl;
	}

	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			dp[i][j] = min(dp[i-1][j]+min(fac[i-1][j].first,fac[i-1][j].second),dp[i][j-1]+min(fac[i][j-1].first,fac[i][j-1].second));
		}
	}

	cout<<dp[n][n]<<endl;

	return 0;
}

