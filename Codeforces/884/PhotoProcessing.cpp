#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
int v[maxn];
int f[maxn]; //how much element can add into groups.
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	sort(v+1,v+1+n);
	int l=0,r=v[n]-v[1];
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int ll=0;
		for(int i=k;i<=n;i++)
		{
			if(v[i]-v[f[i-k]+1]<=mid)
				ll=i;
			f[i]=ll;
		}
		if(f[n]==n)
			r=mid-1;
		else
			l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}