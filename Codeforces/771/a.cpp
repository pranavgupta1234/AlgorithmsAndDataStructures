#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define ll long long 

using namespace std;

bool bfsUtil(vector<vector<int> >& graph,int source,bool* visited){
	ll noEdges = 0;
	ll noVertices = 0;
	queue<int> q;
	visited[source] = true;
	q.push(source);
	noVertices++;
	while(!q.empty()){
		int vis = q.front();
		q.pop();
		for(int i=0 ; i<graph[vis].size() ; i++){
			noEdges++;
			if(!visited[graph[vis][i]]){
				visited[graph[vis][i]] = true;
				q.push(graph[vis][i]);
				noVertices++;
			}
		}
	}
	noEdges = noEdges/2;
	if(noEdges == noVertices*(noVertices-1)/2){
		return true;
	}else{
		return false;
	}
}

bool bfs(vector<vector<int> >& graph){
	bool isclique = true;
	int nodes = graph.size();
	bool* visited = new bool[nodes];
	memset(visited,false,sizeof(visited[0])*nodes);
	for(int i=1 ; i<=nodes-1 ; i++){
		if(!visited[i]){
			isclique = isclique and bfsUtil(graph,i,visited);
		}		
	}
	return isclique;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > graph(n+1,vector<int>(0)); 
	for(int i=0 ; i<m ; i++){
		int s,d;
		cin>>s>>d;
		graph[s].push_back(d);
		graph[d].push_back(s);
	}

	//Yes only if each connected component is a clique and clique means that there is an edge between every pair of nodes
	//and hence no of edges = v(v-1)/2 where v is no of vertices
	if(bfs(graph)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}


	return 0;
}