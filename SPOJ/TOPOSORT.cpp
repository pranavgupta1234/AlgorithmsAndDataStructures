#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

stack<int> stk;
bool isCycle;

int comp(int a,int b){
	return a<b;
}

void dfsUtil(vector<vector<int> >& graph,int s,bool visited[],bool recStack[],int parent){
	visited[s] = true;
	recStack[s] = true;
	for(int i=0 ; i<graph[s].size() ; i++){
		if(visited[graph[s][i]] and recStack[graph[s][i]]){
			isCycle = true;
		}else if(!visited[graph[s][i]]){
			dfsUtil(graph,graph[s][i],visited,recStack,s);
		}
	}
	recStack[s] = false;
	stk.push(s);
}

void toposort(vector<vector<int> >& graph){
	int nodes = graph.size();
	bool visited[nodes];
	bool recStack[nodes];
	memset(visited,false,sizeof(visited[0])*nodes);
	for(int i=1 ; i<=nodes-1 ; i++){
		if(!visited[i]){
			dfsUtil(graph,i,visited,recStack,-1);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<vector<int> > graph(n+1,vector<int>(0));
	for(int i=0 ; i<m ; i++){
		int s,d;
		cin>>s>>d;
		graph[s].push_back(d);
	}

	for(int i=0 ; i<graph.size() ; i++){
		sort(graph[i].begin(),graph[i].end(),comp);
	}

	toposort(graph);

	if(isCycle){
		cout<<"Sandro fails."<<endl;
	}else{
		while(!stk.empty()){
			cout<<stk.top()<<" ";
			stk.pop();
		}
		cout<<endl;
	}
	return 0;
}

