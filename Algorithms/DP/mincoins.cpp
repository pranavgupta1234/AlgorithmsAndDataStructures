#include <iostream>
#include <vector>

#define INT_MAX 1000000007

using namespace std;

int main(){
	
	int n,s;
	cin>>n>>s;
	int cost[n];
	vector<int> coins;
	for(int i=0 ; i<n ; i++){
		cin>>cost[i];
	}

	int dp[s+1];

	for(int i=0 ; i<=s ; i++){
		i == 0 ? dp[i] = 0 : dp[i] = INT_MAX;
	}

	for(int i=1 ; i<=s ; i++){
		for(int j=0 ; j<n ; j++){
			if(cost[j] <= i and dp[i-cost[j]] + 1 < dp[i]){
				dp[i] = dp[i-cost[j]] + 1;
			}
		}
	}

	cout<<dp[s]<<endl;
	for(int i=0 ; i<=s ; i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;

	return 0;
}