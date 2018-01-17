#include <bits/stdc++.h>

using namespace std;

int n;
int costs[120][120];
int res = -1;

void dfs(int u,int p,int c){
	res = max(res,c);
	for(int i=0; i<n ; i++){
		if(i != p and costs[u][i]){
			dfs(i,u,c+costs[u][i]);
		}
	}
}

int main(){
	cin>>n;
	for(int i=1 ; i<n ; i++){
		int s,d,c;
		cin>>s>>d>>c;
		costs[s][d] = c;
		costs[d][s] = c;
 	}

 	dfs(0,-1,0);

 	cout<<res<<endl;

	return 0;
}

