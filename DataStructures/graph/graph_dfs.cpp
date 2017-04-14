#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
private:
	int V;
	list<int>* graph;
	void DFSHelper(int v,bool visited[]);
public:
	Graph(int V);
	void addEdge(int a,int b);
	void DFS(int v);
	void DFS();
};


Graph :: Graph(int v){
	this->V = v;													//in cpp we need to use -> with this because this acts as a pointer and not a reference while in java this is reference so access is done by this.something
	graph = new list<int>[v];
}

void Graph :: addEdge(int u,int v){
	graph[u].push_back(v);
}

void Graph :: DFSHelper(int v,bool visited[]){

	visited[v] = true;
	cout<<v<<" ";

	list<int> :: iterator i;

	for(i = graph[v].begin(); i != graph[v].end(); i++){
		if(!visited[*i]){
			DFSHelper(*i,visited);
		}
	}
}

//this function prints dfs only from a particular vertex and in this case all vertices may not be
//covered if either proper paths does not exist or graph is disconnected 
void Graph :: DFS(int v){

	//initially all vertices are unmarked
	bool *visited = new bool[V];
	for(int i=0;i<V;i++){
		visited[i] = false;
	}

	DFSHelper(v,visited);
}

//this function iterates through all the vertices and
void Graph :: DFS(){

	//initially all vertices are unmarked
	bool *visited = new bool[V];
		for(int i=0;i<V;i++){
			visited[i] = false;
		}

	//print DFS from all vertices
	for(int i=0;i<V;i++){
	 	if(visited[i]==false){
	 		DFSHelper(i,visited);
	 	}
	}
}

int main(){
	
	int V=4;
	int v = 1;
	//Graph* graph = new Graph(4);		//object created on heap so we need to use like graph -> addEdge() etc
	Graph graph(4); 					//object created on stack
	graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal (starting from vertex "<<v<<") \n";
    graph.DFS(v);
    cout<<endl;

}