#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfsUtil(vector< vector<int> >&graph,bool *visited,int s){

	cout<<"Component : "<<endl;
	queue<int> q;

	visited[s] = true;
	q.push(s);

	while(!q.empty()){

		int v = q.front();
		cout<<v<<" ";
		q.pop();

		for(vector<int> :: iterator it = graph[v].begin() ; it != graph[v].end() ; it++){
			if(!visited[*it]){
				visited[*it] = true;
				q.push(*it);
			}
		}

	}

	cout<<endl;
}

void bfs(vector< vector<int> >&graph,int s){

	int V = graph.size();
	int noOfDisconnectedComponents = 0;
	bool visited[V];

	for(int i=0 ; i<V ; i++){
		visited[i] = false;
	}

	for(int i=0 ; i<V ; i++){
		if(!visited[i]){
			noOfDisconnectedComponents++;
			bfsUtil(graph,visited,i);
		}
	}

	cout<<"No of Disconnected Components : "<<noOfDisconnectedComponents;
}

int main(){
	
	int V,E,S;
	cout<<"Enter number of vertices : ";
	cin>>V;
	cout<<"Enter number of edges : ";
	cin>>E;
	cout<<"Enter source vertex for bfs : ";
	cin>>S;

	vector<vector<int> > graph(V,vector<int>(0,0));

	for(int i=0 ; i<E ; i++){
		int s,e;
		cout<<"Source : ";
		cin>>s;
		cout<<"Destination : ";
		cin>>e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	bfs(graph,S);
	
	cout<<endl;
	return 0;
}