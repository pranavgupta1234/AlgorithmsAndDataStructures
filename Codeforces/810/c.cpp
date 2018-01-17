#include <bits/stdc++.h>

using namespace std; 

long long n,a[300007],r[300007],m=1e9+7,sum=0;
int main(){    
	std::cin >> n;
	r[0] = 1;
	for(int i=0 ; i<n ; i++) 	cin>>a[i] , r[i+1]=(r[i]*2)%m ;
	sort(a,a+n);
	for(int i=0 ; i<n ; i++)    sum+=(a[i]*(r[i]-r[n-i-1]))%m , sum%=m;  
	cout<<sum%m;  
}