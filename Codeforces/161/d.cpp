#include <iostream>
#include <vector>
using namespace std;

int n,k,u,v,dp[50001][501],ans=0;
vector<int> graph[50001];

void dfs(int u,int p){
	dp[u][0] = 1;
	for(int i=0 ; i<graph[u].size() ; i++){
		int v = graph[u][i];
		if(v != p){
			dfs(v,u);
			for(int i=1 ; i<=k ; i++){
				ans += dp[u][i-1]*dp[v][k-i];
			}
			for(int i=1 ; i<=k ; i++){
				dp[u][i] += dp[v][i-1];
			}
		}
	} 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	dfs(1,-1);

	cout<<ans<<endl;
	return 0;
}