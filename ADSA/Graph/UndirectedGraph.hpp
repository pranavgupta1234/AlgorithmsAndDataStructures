#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include "AbstractGraph.hpp" 

class UndirectedGraph : AbstractGraph {

private:

  GraphAdjacencyBase* undirectedGraph;


public:
  /*
   * Constructor: UndirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  UndirectedGraph(int vertices, char mode);
  /*
   * Returns the degree of the vertex.
   */
  int degree(int i);

  /* Destructor:
   * releases all resources acquired by the class
   */
  virtual ~UndirectedGraph(){

  }
  /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
  virtual bool edgeExists(int i, int j);
  /*
   * Function: edges
   * Returns the number of edges in the adjacency structure.
   */
  virtual int edges();
  /*
   * Function: vertices
   * Returns the number of vertices in the adjacency structure.
   */
  virtual int vertices();
  /*
   * Function add:
   * Adds an edge between vertices i and j
   */
  virtual void add(int i, int j);
  /*
   * Function: remove
   * Deleted the edge between vertices i and j
   */
  virtual void remove(int i, int j);
  /*
   * Function dfs:
   * Does a depth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  //virtual void dfs(void (*work)(int&));
  /*
   * Function bfs:
   * Does a breadth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  //virtual void bfs(void (*work)(int&));

   void print();

};

UndirectedGraph :: UndirectedGraph(int vertices,char mode){

  switch(mode){
    case 'm':

      undirectedGraph = new AdjacencyMatrix(vertices);

      break;

    case 'l':

      undirectedGraph = new AdjacencyList(vertices);

      break;
  }

}

int UndirectedGraph :: degree(int i){

  return undirectedGraph -> degree(i);

}

int UndirectedGraph :: edges(){

  return undirectedGraph -> edges();

}

int UndirectedGraph :: vertices(){
  
  return undirectedGraph -> vertices();

}

void UndirectedGraph :: add(int i,int j){

  undirectedGraph -> add(i,j);
  undirectedGraph -> add(j,i);

}

void UndirectedGraph :: remove(int i,int j){

  undirectedGraph -> remove(i,j);
  undirectedGraph -> remove(j,i);

}

bool UndirectedGraph :: edgeExists(int i,int j){

  return undirectedGraph -> edgeExists(i,j);

}

void UndirectedGraph :: print(){
      
  undirectedGraph ->print();  

}

#endif /* ifndef UNDIRECTED_GRAPH */