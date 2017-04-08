#include <iostream>
#include <vector>							// vector are contiguous like arrays
#include <list>								// list is implemented by linked lists 
using namespace std;

void addEdge(vector<int> graph[],int src,int dest);
void printGraph(vector<int> graph[],int V);
void BFS(vector<int> graph[],int V,int val);


int main(){

	int V = 6;
	vector<int> graph[V];

	addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printGraph(graph,V);	

    BFS(graph,V,0);

    cout<<endl;

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

void BFS(vector<int> graph[],int V,int val){

	bool* vertices = new bool[V];
	
	for(int k=0;k<V;k++){
		vertices[k]=false;
	}

	//for visited nodes
	list<int> queue;

	vertices[val] = true;
	queue.push_back(val);

	//iterator is subclass of list template class
	vector<int> :: iterator i;

	while(!queue.empty()){

		//deque and print
		int vis = queue.front();
		cout<<vis<<" ";
		queue.pop_front();

		for(i=graph[vis].begin() ; i !=graph[vis].end() ; i++){

			if(!vertices[*i]){
				vertices[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}