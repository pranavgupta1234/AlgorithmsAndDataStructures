#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> graph[],int src,int dest);
void printGraph(vector<int> graph[],int V);

int main(){

	int V = 5;
	vector<int> graph[V];

	addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph,V);	

	return 0;
}

void addEdge(vector<int> graph[],int src,int dest){
	//graph is undirected
	graph[src].push_back(dest);
	graph[dest].push_back(src);
}

void printGraph(vector<int> graph[],int V){

	for(int i=0;i<V;i++){
		cout<<i<<" Head -> ";
		for(int j=0;j<graph[i].size();j++){
			cout<<graph[i].at(j)<<" ";
		}
		cout<<endl;
	}
}

void BFS()