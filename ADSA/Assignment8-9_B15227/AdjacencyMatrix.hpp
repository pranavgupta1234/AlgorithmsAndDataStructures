#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1
#include "GraphAdjacencyBase.hpp"

using namespace std;
using namespace cs202;

class AdjacencyMatrix : public GraphAdjacencyBase {

private:

	int** graphMatrix;
	int V;

public:
	AdjacencyMatrix(int v);
	~AdjacencyMatrix();

	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
	bool edgeExists(int i, int j);
	/*`
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
	void add(int i, int j, int w);
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
    /*
    * Function: getAdjacent
    * Returns array of adjacent nodes of vertex i
    */ 
	LinearList<LinearList<edge> > getAdjacent();
};

AdjacencyMatrix::AdjacencyMatrix(int v){

	V = v;
	graphMatrix = new int*[V];

	for(int i = 0; i < V; i++){
		graphMatrix[i] = new int[V];

		for (int j = 0; j < V; j++){
			graphMatrix[i][j] = 0;
		}
	}
}

AdjacencyMatrix::~AdjacencyMatrix(){

	for (int i = 0; i < V; ++i){
		
		delete[] graphMatrix[i];
	}

	delete[] graphMatrix;
}

bool AdjacencyMatrix::edgeExists(int i, int j){


	return (graphMatrix[i][j] != 0);

}

int AdjacencyMatrix::vertices(){

	return V;
}

int AdjacencyMatrix::edges(){

	int E = 0;

	for(int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			if(graphMatrix[i][j] != 0)
				E++;

	return E;
}

void AdjacencyMatrix::add(int i, int j, int w){

	graphMatrix[i][j] = w;
}

void AdjacencyMatrix::remove(int i, int j){

	graphMatrix[i][j] = 0;
}

int AdjacencyMatrix::degree(int i){

	int nDegree = 0;

	for(int j = 0; j < V; j++)
		if(graphMatrix[i][j] != 0)
			nDegree++;

	for(int j = 0; j < V; j++)
		if(graphMatrix[j][i] != 0)
			nDegree++;

	return nDegree;
}

LinearList<LinearList<edge> > AdjacencyMatrix::getAdjacent(){
	LinearList<LinearList<edge> > adjNodes(V);

	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			if(graphMatrix[i][j] != 0)
				adjNodes[i].push_back(edge(i, j, graphMatrix[i][j]));

	return adjNodes; 
}


#endif /* ifndef ADJACENCY_MATRIX */