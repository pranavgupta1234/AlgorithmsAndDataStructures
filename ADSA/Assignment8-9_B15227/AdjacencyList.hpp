#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1
#include "GraphAdjacencyBase.hpp"

using namespace cs202;
using namespace std;

class AdjacencyList : public GraphAdjacencyBase {

private:
	LinearList<list<edge> > graphList;
	int V;

public:

	AdjacencyList(int v);
	~AdjacencyList(){};

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

AdjacencyList::AdjacencyList(int v){

	V = v;
	graphList.resize(v);
}

bool AdjacencyList::edgeExists(int i, int j){

	node<edge>* it = graphList[i].getIterator();

	while(it){
		if(it->data == edge(i, j, 0))
			return true;
		it = it->next;
	}

	return false;
}
	
int AdjacencyList::vertices(){
	return V;
}
	
int AdjacencyList::edges(){
	int E = 0;

	for(int i = 0; i < V; i++)
		E += graphList[i].length();

	return E;
}
	
void AdjacencyList::add(int i, int j, int w){

	if(!edgeExists(i, j))
		graphList[i].append(edge(i, j, w));
}

void AdjacencyList::remove(int i, int j){

	graphList[i].remove(edge(i, j, 0));
}

int AdjacencyList::degree(int i){

	int nDegree = graphList[i].length();

	for(int j = 0; j < V; j++)
		if(j != i && edgeExists(j, i))
			nDegree++;

	return nDegree;
}

LinearList<LinearList<edge> > AdjacencyList::getAdjacent(){

	LinearList<LinearList<edge> > adjNodes(V);

	for(int i = 0; i < V; i++){
		node<edge>* it = graphList[i].getIterator();

		while(it){

			adjNodes[i].push_back(it->data);
			it = it->next;
		}
	}

	return adjNodes;


}
#endif /* ifndef ADJACENCY_LIST */
