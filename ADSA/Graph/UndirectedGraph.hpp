#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include "AbstractGraph.hpp" 
#include "queue.hpp"
#include "stack.hpp"

class UndirectedGraph : AbstractGraph {

private:

  GraphAdjacencyBase* undirectedGraph;
  char rep;


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
  virtual void dfs(void (*work)(int&));
  /*
   * Function bfs:
   * Does a breadth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  virtual void bfs(void (*work)(int&));

   void print();

};

UndirectedGraph :: UndirectedGraph(int vertices,char mode){

  switch(mode){
    case 'm':

        undirectedGraph = new AdjacencyMatrix(vertices);
        rep = 'm';
        break;

    case 'l':

        undirectedGraph = new AdjacencyList(vertices);
        rep = 'l';
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

void UndirectedGraph :: bfs(void (*work)(int&)){

    int** g = undirectedGraph -> getGraph();

    bool* vertices = new bool[undirectedGraph -> vertices()];
  
    for(int k=0 ; k < undirectedGraph -> vertices() ; k++){
        vertices[k]=false;
    }

    for(int i=0 ; i<undirectedGraph -> vertices() ; i++){

        if(!vertices[i]){


            //for visited nodes
            q::queue<int> q;

            vertices[i] = true;
            q.push(i);

            while(!q.empty()){

                //deque and print
                int vis = q.front();
                work(vis);                
                q.pop();

                if(rep == 'm'){
                    for(int j = 0 ; j < undirectedGraph -> vertices() ; j++){

                        int v = (g[vis][j] != 0 ? j : 0);
                        if(v != 0){
                            if(!vertices[v]){
                                vertices[v] = true;
                                q.push(v);
                            }                
                        }
                    }            
                }else{

                    cs202::LinearList<int>* g = undirectedGraph -> getList(vis);

                    for(int k=0 ; k< g->length() ; k++){

                        int v = (*g)[k];
                
                        if(!vertices[v]){
                            vertices[v] = true;
                            q.push(v);
                        }
                    }  
                }
            }

        }

    }
}

void UndirectedGraph :: dfs(void (*work)(int&)){

    bool* vertices = new bool[undirectedGraph -> vertices()];
  
    for(int k=0 ; k < undirectedGraph -> vertices() ; k++){
        vertices[k]=false;
    }

    for(int i=0 ; i < undirectedGraph -> vertices() ; i++){

        if(!vertices[i]){
            // Create a stack for DFS
            stk::stack<int> stack;

            // Push the current source node.
            stack.push(i);
 
            while (!stack.empty()){
        
                // Pop a vertex from stack and print it
                int s = stack.top();
                stack.pop();
 
                // Stack may contain same vertex twice. So
                // we need to print the popped item only
                // if it is not visited.
                if (!vertices[s]){
                    work(s);
                    vertices[s] = true;
                }
 
                // Get all adjacent vertices of the popped vertex s
                // If a adjacent has not been visited, then push it
                // to the stack.
                if(rep == 'm'){

                    int** g = undirectedGraph -> getGraph();

                    for(int i = 0 ; i < undirectedGraph -> vertices() ; i++){

                        int v = (g[s][i] != 0 ? i : 0);
                        if(v != 0){
                            if(!vertices[v]){
                                stack.push(v);                    
                            }                
                        }
                    }            
                }else{

                    cs202::LinearList<int>* g = undirectedGraph -> getList(s);

                    for(int j=0 ; j< g->length() ; j++){

                        int v = (*g)[j];

                        if(!vertices[v]){
                            stack.push(v);
                        }
                    }
                }
            }
        }

    } 
}



#endif /* ifndef UNDIRECTED_GRAPH */