#ifndef ABSTRACT_GRAPH
#define ABSTRACT_GRAPH 1

#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"
#include "GraphAdjacencyBase.hpp"
/*
 * An interface to represent any type of Graph
 */

//This is an abstract class and can't be instantiated
class AbstractGraph {

 public:

  /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
  virtual bool edgeExists(int i, int j) = 0;
  /*
   * Function: edges
   * Returns the number of edges in the adjacency structure.
   */
  virtual int edges() = 0;
  /*
   * Function: vertices
   * Returns the number of vertices in the adjacency structure.
   */
  virtual int vertices() = 0;
  /*
   * Function add:
   * Adds an edge between vertices i and j
   */
  virtual void add(int i, int j) = 0;
  /*
   * Function: remove
   * Deleted the edge between vertices i and j
   */
  virtual void remove(int i, int j) = 0;
  /*
   * Function dfs:
   * Does a depth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  //virtual void dfs(void (*work)(int&)) = 0;
  /*
   * Function bfs:
   * Does a breadth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  //virtual void bfs(void (*work)(int&)) = 0;

};
#endif /* ifndef ABSTRACT_GRAPH */