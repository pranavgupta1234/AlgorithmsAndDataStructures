#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1
#include "AbstractGraph.hpp"

using namespace std;
using namespace cs202;
/*
 * A class to represent a directed graph.
 */
class DirectedGraph : public AbstractGraph {
private:

  GraphAdjacencyBase* graph;

public:
  /*
   * Constructor: DirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  DirectedGraph(int V, char r);
  /*
   * Function: indegree
   * Returns the indegree of a vertex
   */
  int indegree(int i);
  /*
   * Function: outdegree
   * Returns the outdegree of a vertex.
   */
  int outdegree(int i);
  /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
  bool edgeExists(int i, int j);
  /*
   * Function: edges
   * Returns the number of edges in the adjacency structure.
   */
  int edges();
  /*
   * Function: vertices
   * Returns the number of vertices in the adjacency structure.
   */
  int vertices();
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
   * Function dfs:
   * Does a depth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  void dfs(void (*work)(int&));
  /*
   * Function bfs:
   * Does a breadth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  void bfs(void (*work)(int&));
  /*
   * Function kruskal:
   * Finds minimum spaning of the graph
   * Runs the given funciton work with the value of each node in tree
   */

};

DirectedGraph::DirectedGraph(int numVertices, char rep){

  if(rep != 'm' && rep != 'M' && rep != 'l' && rep != 'L'){
    cout<<"**Invalid mode. Using adjacency list mode as default.\n";
    rep = 'l';
  }

  if(rep == 'm' || rep == 'M'){
    graph = new AdjacencyMatrix(numVertices);
  }
  else{
    graph = new AdjacencyList(numVertices); 
  }
}

int DirectedGraph::indegree(int i){

  int degree = 0;
  for(int j = 0; j < graph->vertices(); j++){
    if(j != i && graph->edgeExists(j, i))
      degree++;
  }

  return degree;
}

int DirectedGraph::outdegree(int i){

  int degree = 0;
  for(int j = 0; j < graph->vertices(); j++){
    if(j != i && graph->edgeExists(i, j))
      degree++;
  }

  return degree;
}

bool DirectedGraph::edgeExists(int i, int j){

  return graph->edgeExists(i, j);
}

int DirectedGraph::edges(){

  return graph->edges();
}

int DirectedGraph::vertices(){

  return graph->vertices();
}

void DirectedGraph::add(int i, int j, int w){

  graph->add(i, j, w);
}

void DirectedGraph::remove(int i, int j){

  graph->remove(i, j);
}

void DirectedGraph::dfs(void (*work)(int&)){

  Color color[graph->vertices()];

  for(int i = 0; i < graph->vertices(); i++)
    color[i] = WHITE;

  stack<int> dfsStack;

  int i = 0, j;
  LinearList<LinearList<edge> > adjNodes = graph->getAdjacent();

  bool allVisited = false;
  while(!allVisited){
    while(!dfsStack.empty()){
       i = dfsStack.top();

      if(adjNodes[i].size() > 0){
        j = adjNodes[i][0].dest;
        adjNodes[i].erase_pos(0);
        if(color[j] == WHITE){
          dfsStack.push(j);
          color[j] = GRAY;
          (*work)(j);
        }
      }
      else{
        color[i] = BLACK;
        dfsStack.pop();
      }
    }

    allVisited = true;
    for(j = 0; j < graph->vertices(); j++)
      if(color[j] == WHITE){
        allVisited = false;
        dfsStack.push(j);
        (*work)(j);
        color[j] = GRAY;
        break;
      }
  }
}

void DirectedGraph::bfs(void (*work)(int&)){
  
  Color color[graph->vertices()];

  for(int i = 0; i < graph->vertices(); i++)
    color[i] = WHITE;

  queue<int> bfsQueue;

  int i = 0, j;
  LinearList<LinearList<edge> > adjNodes = graph->getAdjacent();

  bool allVisited = false;
  while(!allVisited){
    while(!bfsQueue.empty()){
       i = bfsQueue.front();

      if(adjNodes[i].size() > 0){
        j = adjNodes[i][0].dest;
        adjNodes[i].erase_pos(0);
        if(color[j] == WHITE){
          bfsQueue.push(j);
          color[j] = GRAY;
          (*work)(j);
        }
      }
      else{
        color[i] = BLACK;
        bfsQueue.pop();
      }
    }

    allVisited = true;
    for(j = 0; j < graph->vertices(); j++)
      if(color[j] == WHITE){
        allVisited = false;
        bfsQueue.push(j);
        (*work)(j);
        color[j] = GRAY;
        break;
      }
  }
}

#endif /* ifndef DIRECTED_GRAPH */