#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,k;
long long f[2005][2005];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	f[1][0]=m;
	for(int i=1;i<n;++i)
		for(int j=0;j<=k;++j)
			(f[i+1][j]+=f[i][j])%=MOD,
			(f[i+1][j+1]+=f[i][j]*(m-1))%=MOD;
	printf("%d\n",int(f[n][k]));
}