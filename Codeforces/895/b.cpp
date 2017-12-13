#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n,x,k; 
	cin>>n>>x>>k;
	long long a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long sum=0;
	for (int i=0;i<n;i++){
		long long p=((a[i]+x-1)/x)*x;
		sum+=lower_bound(a,a+n,p+k*x)-lower_bound(a,a+n,max(a[i],p+(k-1)*x));
	}
	cout<<sum<<"\n";
}