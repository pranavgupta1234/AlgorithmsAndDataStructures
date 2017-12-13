#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

//returns cost from a specific disconnected component
long bfsUtil(vector<vector<int> >& graph,int source,bool* visited,vector<long>& costs){
	long mincost = LONG_MAX;
	queue<int> q;
	q.push(source);
	visited[source] = true;
	mincost = min(costs[source],mincost);
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		mincost = min(costs[curr],mincost);
		for(int i=0 ; i<graph[curr].size() ; i++){
			if(!visited[graph[curr][i]]){
				visited[graph[curr][i]] = true;
				q.push(graph[curr][i]);
			}
		}
	}
	return mincost;
}

//returns least cost from all of disconnected components
long long bfs(vector<vector<int> >& graph,vector<long>& costs){
	long long leastCostAllComponent = 0;
	int nodes = graph.size()-1;
	bool *visited = new bool[nodes+1];
	memset(visited,false,sizeof(visited[0])*nodes); 
	for(int i=1 ; i<=nodes ; i++){
		if(!visited[i]){
			leastCostAllComponent += bfsUtil(graph,i,visited,costs);
		}
	}
	return leastCostAllComponent;
}

int main(){
	int n,v;
	cin>>n>>v;
	vector<long> costs(n+1,0);
	vector<vector<int> > graph(n+1,vector<int>(0));
	for(int i=1 ; i<=n ; i++){
		cin>>costs[i];
	}
	if(v == 0){
		long long sum = 0;
		for(int i=0 ; i<costs.size() ; i++){
			sum += costs[i];
		}
		cout<<sum<<endl;
	}else{
		for(int i=0 ; i<v ; i++){
			int start,end;
			cin>>start>>end;
			graph[start].push_back(end);
			graph[end].push_back(start);
		}
		cout<<bfs(graph,costs)<<endl;
	}
	return 0;
}