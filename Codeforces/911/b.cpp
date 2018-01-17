#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b;
	cin>>n>>a>>b;
	int ans = 0;
	for(int x =1 ; x< n ; x++){
		ans = max(ans,min(a/x,b/(n-x)));
	}
	cout<<ans<<endl;
	return 0;
}