#include<bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define N 1001

using namespace std;

typedef long long ll;

ll dp[N][2*N][2];
ll MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	dp[1][1][0] = 2;
	dp[1][2][0] = 0;
	dp[1][1][1] = 0;
	dp[1][2][1] = 2;
	for(int i = 2 ; i <= n ; ++i) {
		for(int j = 1 ; j <= min(2*n, k) ; ++j) {
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j - 1][0] + dp[i - 1][j][1] * 2;
			dp[i][j][0] %= MOD;
			dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j - 2][1] + dp[i - 1][j - 1][0] * 2;
			dp[i][j][1] %= MOD;
		}
	}
	cout << (dp[n][k][0] + dp[n][k][1]) % MOD << endl;
    return 0;
}