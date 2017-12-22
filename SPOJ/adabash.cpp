#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void dfsUtil(vector<vector<int> >& graph,bool* visited,int source){
	visited[source] = true;
	for(int i=0 ; i<graph[source].size() ; i++){
		if(!visited[graph[source][i]]){
			dfsUtil(graph,visited,graph[source][i]);
		}
	}
}	

int dfs(vector<vector<int> >& graph){
	int components = 0;
	int nodes = graph.size();
	bool* visited = new bool[nodes];
	memset(visited,false,sizeof(visited[0])*nodes);
	for(int i=1 ; i<=nodes-1 ; i++){
		if(!visited[i]){
			components++;
			dfsUtil(graph,visited,i);
		}
	}
	return components;
}

int main(){
	
	int n,m;
	cin>>n>>m;
	vector<vector<int> > graph(n+1,vector<int>(0));
	for(int i=0 ;i<m ; i++){
		int s,d;
		cin>>s>>d;
		graph[s].push_back(d);
		graph[d].push_back(s);
	}

	cout<<dfs(graph)<<endl;

	return 0;
}