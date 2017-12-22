#include <bits/stdc++.h>

#define range 1000007

using namespace std;

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> timing(n,0);
	int freq[range];
	memset(freq,0,sizeof(freq[0])*range);
	for(int i=0 ; i<n ; i++){
		cin>>timing[i];
		freq[timing[i]]++;
	}
	sort(timing.begin(),timing.end());
	int ans = 0;
	for(int i=0 ; i<timing.size() ; i++){
		int low = timing[i];
		int high = timing[i] + m;
		int alarmbw = upper_bound(timing.begin(),timing.end(),high) - lower_bound(timing.begin(),timing.end(),low) - 1;
		while(alarmbw >= k){
			alarmbw--;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}