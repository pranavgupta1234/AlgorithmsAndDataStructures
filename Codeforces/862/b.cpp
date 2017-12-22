#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define ll long long

using namespace std;

ll bfs(vector<vector<int> >& graph){
	ll x = 0;
	ll y = 0;

	int nodes = graph.size();
	int source = 1;
	bool visited[nodes];
	int distances[nodes];
	memset(distances,0,sizeof(distances[0])*nodes);
	memset(visited,false,sizeof(visited[0])*nodes);
	queue<int> q;
	visited[source] = true;
	q.push(source);
	distances[source] = 0;
	x++;
	while(!q.empty()){
		int vis = q.front();
		q.pop();
		for(int i=0 ; i<graph[vis].size() ; i++){
			if(!visited[graph[vis][i]]){
				visited[graph[vis][i]] = true;
				distances[graph[vis][i]] = distances[vis] + 1;
				if(distances[graph[vis][i]] & 1){
					y++;
				}else{
					x++;
				}
				q.push(graph[vis][i]);
			}
		}
	}	

	return x*y;
}

int main(){
	int n;										//no of nodes in a tree
	cin>>n;										//every tree is bipartite graph if we consider nodes at alternative level in two diff subsets
	vector<vector<int> > graph(n+1,vector<int>(0));	
	for(int i=0 ; i<n-1 ; i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	//x is no of vertices in Set A and y in set B then xy is total number of edges between A and B
	//xy is total number of possible edges between two set of vertices of bipartite graph which are basically 
	//nodes at alternative level in a tree
	ll xy = bfs(graph);
	cout<<xy-(n-1)<<endl;
	return 0;
}