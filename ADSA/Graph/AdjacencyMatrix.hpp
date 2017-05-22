#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1
#include "GraphAdjacencyBase.hpp"
class AdjacencyMatrix : public GraphAdjacencyBase {

private:

	int** graph;
	int V,E;


public: 

   AdjacencyMatrix();

   AdjacencyMatrix(int V);

  	/* Destructor:
	 * releases all resources acquired by the class
	 */
  ~AdjacencyMatrix();

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

AdjacencyMatrix :: AdjacencyMatrix(){

	graph = NULL;
	E =0;
	V =0;

}


AdjacencyMatrix :: AdjacencyMatrix(int V){

	this -> V = V;
	E = 0;

	graph = new int*[V];

	for(int i=0 ; i< V ; i++){
		graph[i] = new int[V];
	}

	for(int i=0 ; i<V ; i++){

		for(int j=0 ; j< V ; j++){
			graph[i][j] = 0;
		}

	}

}

bool AdjacencyMatrix :: edgeExists(int i , int j){

	return (graph[i][j] != 0 ? true : false);

}

int AdjacencyMatrix :: vertices(){
	return V;
}

int AdjacencyMatrix :: edges(){
	return E;
}

void AdjacencyMatrix :: add(int i,int j,int w){

	E++;

	if(i < V and j < V){
		graph[i][j] = w;
	}
}

void AdjacencyMatrix :: remove(int i,int j){
	
	if(i < V and j <V){
		graph[i][j] = 0;
	}

	E--;
}

int AdjacencyMatrix :: degree(int i){

	int deg = 0;

	for(int j=0 ; j < V ; j++){

		if(graph[i][j] != 0){
			deg++;
		}
	}

	return deg;
}

void AdjacencyMatrix :: print(){

	for(int i=0; i < V ; i++){
      
        for(int j=0 ; j < V ; j++){
        
          std::cout<<graph[i][j]<<" ";
        
        }       

      std::cout<<std::endl;
    
    }

}

int** AdjacencyMatrix :: getGraph(){

	return graph;
}

int AdjacencyMatrix :: OutDegreeHelper(int i){

}

cs202::LinearList<int>* AdjacencyMatrix :: getList(int i){
	
}

#endif /* ifndef ADJACENCY_MATRIX */