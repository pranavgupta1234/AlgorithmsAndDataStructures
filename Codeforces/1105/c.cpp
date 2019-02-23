#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
int f[200001][3] = {0};

int main(){

	f[0][0] = 1;
	int n, l, r;
	cin >> n >> l >> r;
	int len = r - l + 1;
	int c[3] = {len / 3, len / 3, len / 3};
	int last = l + len / 3 * 3 - 1;
	for (int i = last + 1; i <= r; i++)
		c[i%3]++;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				(f[i][(j+k)%3] += 1ll * f[i-1][j] * c[k] % M) %= M;
	cout << f[n][0] << '\n';
	
    return 0;
}