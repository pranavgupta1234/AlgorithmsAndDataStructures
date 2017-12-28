#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool isCycle = false;

void dfsUtil(vector<vector<int> >& graph,int s,bool visited[],bool recStack[],int parent){
	visited[s] = true;
	recStack[s] = true;
	for(int i=0 ; i<graph[s].size() ; i++){
		// graph[s][i] != parent is used because loop is not a cycle
		if(visited[graph[s][i]] and recStack[graph[s][i]]){
			//cycle detected
			isCycle = true;
		}else if(!visited[graph[s][i]]){
			dfsUtil(graph,graph[s][i],visited,recStack,s);
		}
	}
	recStack[s] = false;
}

void dfs(vector<vector<int> >& graph){
	int nodes = graph.size();
	bool visited[nodes];
	bool recStack[nodes];
	memset(visited,false,sizeof(visited[0])*nodes);
	memset(recStack,false,sizeof(recStack[0])*nodes);
	for(int i=1 ; i<=nodes-1 ; i++){
		if(!visited[i]){
			dfsUtil(graph,i,visited,recStack,-1);
		}
	}
}

//union find will not work here
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > graph(n+1,vector<int>(0));
	for(int i=0 ; i<m ; i++){
		int s,d;
		cin>>s>>d;
		graph[s].push_back(d);
	}

	dfs(graph);

	if(isCycle){
		cout<<"Cycle+"<<endl;
	}else{
		cout<<"Cycle-"<<endl;
	}

	return 0;
}	