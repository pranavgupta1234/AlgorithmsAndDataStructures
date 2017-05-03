#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1
#include "GraphAdjacencyBase.hpp"
#include "seqLinearList.hpp"


class AdjacencyList : public GraphAdjacencyBase {

private:

	cs202::LinearList<int>** graph;
	int V,E;

public:

	AdjacencyList();

	AdjacencyList(int V);

	 /* Destructor:
	 * releases all resources acquired by the class
	 */
  	~AdjacencyList();
	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
  	bool edgeExists(int i, int j);
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
 	int vertices();
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
  	int edges();
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
  	void add(int i, int j);
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
 	void remove(int i, int j);
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
  	int degree(int i);

  	void print();

  	int** getGraph();

  	int OutDegreeHelper(int i);

  	cs202::LinearList<int>* getList(int i);

};

AdjacencyList :: AdjacencyList(){

	graph = NULL;

	V = 0;
	E = 0;

}

AdjacencyList :: AdjacencyList(int v){

	graph = new cs202::LinearList<int>* [v];

	for(int i=0 ; i < v ; i++){
		graph[i] = new cs202::LinearList<int>();
	}

	V = v;
	E = 0;

}

bool AdjacencyList :: edgeExists(int i,int j){

	cs202::LinearList<int>* g = graph[i];

	return g -> find(j);

}

int AdjacencyList :: edges(){

	return E;

}

int AdjacencyList :: vertices(){

	return V;

}

void AdjacencyList :: add(int i,int j){

	if(!(graph[i] -> find(j))){
		graph[i] -> push_back(j);
		E++;
	}
}

void AdjacencyList :: remove(int i,int j){

	if(graph[i] -> find(j)){
		graph[i] -> erase(j);
		E--;		
	}
}

int AdjacencyList :: degree(int i){

	cs202::LinearList<int>* g = graph[i];

	return g -> length();
}

int AdjacencyList :: OutDegreeHelper(int i){

	int out_deg = 0;

	for(int j = 0 ; j < V ; j++){

		cs202::LinearList<int>* g = graph[j];

		if( g -> find(i)){
			out_deg++;
		}

	}

	return out_deg;

}

void AdjacencyList :: print(){

	for(int i=0 ; i<V ; i++){

		cs202::LinearList<int>* g = graph[i];

		g -> print();
	}
}

int** AdjacencyList :: getGraph(){

}

cs202::LinearList<int>* AdjacencyList :: getList(int i){

	return graph[i];

}


#endif /* ifndef ADJACENCY_LIST */