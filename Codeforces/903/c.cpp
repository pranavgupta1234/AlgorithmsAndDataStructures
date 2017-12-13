#include <bits/stdc++.h>
using namespace std;

int n,ans;
map<int, int> g;

int main() {
	cin>>n;
	for(int i=0 ; i<n ; i++){
		int t;
		cin>>t;
		ans = max(ans,++g[t]);
	}
	cout<<ans<<endl;
}