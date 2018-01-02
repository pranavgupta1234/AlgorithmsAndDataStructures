#include <bits/stdc++.h>

using namespace std;

int color[100100];
int dist[100100];
vector<int> graph[100100];

void dfs(int s,int p){
	dist[s] = 0;
	if(color[s] == 1)	{	dist[s] += 1;	}
	for(int i=0 ; i<graph[s].size() ; i++){
		if(graph[s][i] != p){
			dfs(graph[s][i],s);
			dist[s] += dist[graph[s][i]];
		}
	}
}	

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;

	for(int i=1 ; i<n ; i++){
		int s,d,c;
		cin>>s>>d>>c;
		graph[s].push_back(d);
		graph[d].push_back(s);
		if(c == 2) color[s] = color[d] = 1; 
	}

	dfs(1,0);
	int no = 0;
	for(int i=1 ; i<=n ; i++) if(dist[i] == 1)  no++ ;
	cout<<no<<endl;
	for(int i=1 ; i<=n ; i++) if(dist[i] == 1) cout<<i<<" ";
	cout<<endl;
	return 0;
}