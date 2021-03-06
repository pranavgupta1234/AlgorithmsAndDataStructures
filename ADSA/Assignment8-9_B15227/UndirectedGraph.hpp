#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include "AbstractGraph.hpp"
#include "minPriorityQueue.hpp"

class UndirectedGraph : public AbstractGraph {
private:

  GraphAdjacencyBase* graph;

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
  void kruskal(void (*work)(int&, int&, int&));

  void primMST();

};

UndirectedGraph::UndirectedGraph(int numVertices, char rep){

  if(rep != 'm' && rep != 'M' && rep != 'l' && rep != 'L'){
    cout<<"Invalid mode. using l by default.\n";
    rep = 'l';
  }

  if(rep == 'm' || rep == 'M'){
    graph = new AdjacencyMatrix(numVertices);
  }
  else{
    graph = new AdjacencyList(numVertices); 
  }

}

int UndirectedGraph::degree(int i){

  if(edgeExists(i, i))
    return (graph->degree(i) + 3) / 2;
  else
    return graph->degree(i) / 2;
}

bool UndirectedGraph::edgeExists(int i, int j){

  return graph->edgeExists(i, j);
}

int UndirectedGraph::edges(){

  int E = 0;

  for(int i = 0; i < graph->vertices(); i++)
    for(int j = i; j < graph->vertices(); j++)
      if(edgeExists(i, j))
        E++;

  return E;
}

int UndirectedGraph::vertices(){

  return graph->vertices();
}

void UndirectedGraph::add(int i, int j, int w){

  if(!edgeExists(i, j)){
    graph->add(i, j, w);

    if(i != j)
      graph->add(j, i, w);
  }
}

void UndirectedGraph::remove(int i, int j){

  graph->remove(i, j);
  graph->remove(j, i);
}

void UndirectedGraph::dfs(void (*work)(int&)){

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
      
      }else{
       
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

void UndirectedGraph::bfs(void (*work)(int&)){
  
    Color color[graph->vertices()];

    for(int i = 0; i < graph->vertices(); i++)
        color[i] = WHITE;

    queue<int> queue;

    int i = 0, j;
    LinearList<LinearList<edge> > adjNodes = graph->getAdjacent();

    bool allVisited = false;
    while(!allVisited){
        while(!queue.empty()){
            i = queue.front();

            if(adjNodes[i].size() > 0){

                j = adjNodes[i][0].dest;
                adjNodes[i].erase_pos(0);
        
                if(color[j] == WHITE){
        
                    queue.push(j);
                    color[j] = GRAY;
                    (*work)(j);
                }

            }else{
       
                color[i] = BLACK;
                queue.pop();
      
            }
    
        }

    allVisited = true;
    
    for(j = 0; j < graph->vertices(); j++)
    
      if(color[j] == WHITE){
    
        allVisited = false;
        queue.push(j);
        (*work)(j);
        color[j] = GRAY;
        break;
    
      }
  }

}


void UndirectedGraph::kruskal(void (*work)(int&, int&, int&)){

    LinearList<LinearList<edge> > edges = graph->getAdjacent();  
    LinearList<edge> allEdges(graph->edges());

    for(int i = 0; i < vertices(); i++){
        for(int j = 0; j < edges[i].size(); j++){
            allEdges.push_back(edges[i][j]);
        }
    }
    

    qsort(&allEdges[0], allEdges.size(), sizeof(edge), edgeCompare);

    UFDS sets(vertices());

    int u = 0, v;
    int weight;

    while(sets.num_disjoint_sets() != 1){
  
        if(allEdges.size() == 0)
             cout<<"Graph is not complete";
    
        u = allEdges[0].src;
        v = allEdges[0].dest;

        weight = allEdges[0].weight;
        allEdges.erase_pos(0);

        if(!sets.is_same_set(u, v)){

            (*work)(u, v, weight);
            sets.union_set(u, v);
        }
    }
}  

void UndirectedGraph::primMST(){

    LinearList<LinearList<edge>> edges = graph -> getAdjacent();

    const int no_of_vertices = graph -> vertices();

    int* parent = new int[no_of_vertices];
    int* visited = new int[no_of_vertices];
    int* key = new int[no_of_vertices];
    
    MinPriorityQueue<vertexHeap> heap;

    for(int i=0 ; i < no_of_vertices ; i++){
        parent[i] = -1;
        visited[i] = 0;
    }

    for(int i=0 ; i < no_of_vertices ; i++){
        heap.insert(vertexHeap(i,INT_MAX));
        key[i] = INT_MAX;
    }

    heap.heap_decrease_key(0);

    while(!heap.empty()){

        vertexHeap u = heap.extract_min();
        visited[u.v] = 1;

        for(int i=0 ; i< edges[u.v].size() ; i++){

            edge v = edges[u.v][i];

            if(visited[v.dest] == 0){

                if(v.weight < key[v.dest]){
                 
                    key[v.dest] = v.weight;
                    heap.heap_decrease_key(v.dest,vertexHeap(v.dest,v.weight));
                    parent[v.dest] = v.src; 
                
                }

            }
        }
    }

    cout<<"The edges included in MST are :: "<<endl;
    for(int i=0 ; i<no_of_vertices ; i++){
      if(parent[i] != -1){
        cout<<parent[i]<<"->"<<i<<endl;
      }
    }
    cout<<endl;
}


#endif /* ifndef UNDIRECTED_GRAPH */