#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1
#include "AbstractGraph.hpp"
#include "queue.hpp"
#include "stack.hpp"
/*
 * A class to represent a directed graph.
 */
class DirectedGraph : AbstractGraph {

private:

    GraphAdjacencyBase* directedGraph;
    char rep;


public:
    /*
    * Constructor: DirectedGraph
    *
    * Parameters: mode
    * Used to decide which representation to use
    * 'm' for AdjacencyMatrix
    * 'l' for AdjacencyList
    */
    DirectedGraph(int numVertices, char rep);
    /*
    * Function: indegree
    * Returns the indegree of a vertex
    */
    int indegree(int i);
    /*
    * Function: outdegree
    * Returns the outdegree of a vertex.
    */
    int outdegree(int j);
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
    void add(int i, int j);
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


    void print();

};

DirectedGraph :: DirectedGraph(int numVertices,char r){

    switch(r){

        case 'm':

            directedGraph = new AdjacencyMatrix(numVertices); 
            rep = 'm';
            break;

        case 'l':

            directedGraph = new AdjacencyList(numVertices);
            rep = 'l';
            break;
    }

}

int DirectedGraph :: indegree(int i){

    if(rep == 'm'){

        int** g = directedGraph -> getGraph();
        int in_deg = 0;

        for(int j=0;j<directedGraph->vertices();j++){

            if(g[i][j] == 1){
                in_deg ++;
            }
        }

        return in_deg;
    }else{

        directedGraph -> OutDegreeHelper(i);

    }


}

int DirectedGraph :: outdegree(int i){

    if(rep == 'm'){

    int** g = directedGraph -> getGraph();

    int out_deg = 0;

        for(int j=0;j<directedGraph->vertices();j++){

            if(g[j][i] == 1){
                out_deg ++;
            }
        }

        return out_deg; 
    }else{

        return directedGraph -> degree(i);

    }
    
}

bool DirectedGraph :: edgeExists(int i,int j){

    return directedGraph -> edgeExists(i,j);
}

int DirectedGraph :: edges(){
    return directedGraph -> edges();
}

int DirectedGraph :: vertices(){
    return directedGraph -> vertices();
}

void DirectedGraph :: add(int i,int j){

    directedGraph -> add(i,j);

}

void DirectedGraph :: remove(int i,int j){

    directedGraph -> remove(i,j);

}

void DirectedGraph :: print(){

    directedGraph ->print();

}

void DirectedGraph :: bfs(void (*work)(int&)){

    int** g = directedGraph -> getGraph();

    bool* vertices = new bool[directedGraph -> vertices()];
  
    for(int k=0 ; k < directedGraph -> vertices() ; k++){
        vertices[k]=false;
    }

    //for visited nodes
    q::queue<int> q;

    vertices[0] = true;
    q.push(0);

    while(!q.empty()){

        //deque and print
        int vis = q.front();
        work(vis);                
        q.pop();
        if(rep == 'm'){
            for(int i = 0 ; i < directedGraph -> vertices() ; i++){

                int v = (g[vis][i] != 0 ? i : 0);
                if(v != 0){
                    if(!vertices[v]){
                        vertices[v] = true;
                        q.push(v);
                    }                
                }

            }            
        }else{

            cs202::LinearList<int>* g = directedGraph -> getList(i);

            for(int j=0 ; j< g->length() ; j++){

                int v = (*g)[j];
                
                if(!vertices[v]){
                    vertices[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

void DirectedGraph :: dfs(void (*work)(int&)){

    bool* vertices = new bool[directedGraph -> vertices()];
  
    for(int k=0 ; k < directedGraph -> vertices() ; k++){
        vertices[k]=false;
    }

    for(int i=0 ; i < directedGraph -> vertices() ; i++){

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

                    int** g = directedGraph -> getGraph();

                    for(int i = 0 ; i < directedGraph -> vertices() ; i++){

                        int v = (g[s][i] != 0 ? i : 0);
                        if(v != 0){
                            if(!vertices[v]){
                                stack.push(v);                    
                            }                
                        }
                    }            
                }else{

                    cs202::LinearList<int>* g = directedGraph -> getList(s);

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

#endif /* ifndef DIRECTED_GRAPH */