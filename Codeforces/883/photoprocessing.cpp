#include <bits/stdc++.h>

using namespace std;

const int maxx = 3 * 1e5 + 20;
int a[maxx] , DP[maxx];
int n , k;

bool valid(int mid){
	int last = 0;
	for(int i = k ; i <= n ; i++){
		if(a[i] - a[DP[i - k] + 1] <= mid){
			last = i;
		}
		DP[i] = last;	
	}
	return (DP[n] == n);
}

int main()
{
	cin>>n>>k;
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);	
	int st = 0;
	int en = a[n] - a[1];
	while(st<en){
		int mid = (en + st)>>1;
		if(valid(mid)){
			en = mid;
		}
		else{
			st = mid + 1;	
		}
	}
	cout<<st<<endl;	
}