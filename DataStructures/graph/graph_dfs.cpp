#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
private:
	int V;
	vector<int>* graph;
	void DFSHelper(int v,bool visited[]);
public:
	Graph(int V);
	void addEdge(int a,int b);
	void DFS(int v);
};


Graph :: Graph(int v){
	this.V = v;
}

int main(){
	
	int V=6;
	vector<int> graph[V];




}