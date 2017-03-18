#include <iostream>
#define ROW 5
#define COL 5

using namespace std;

/* while using typedef in struct then c compiler needs the struct notation inside the struct body as it has not typedefed the value
while it is not necessary in c++ compiler. But always remember to declare a struct before using in other(clear dependencies first). 
For eg using ArrayList before GraphNode will cause error because ArrayList depends upon GraphNode.
*/ 
typedef struct GraphNode{
	int data;
	GraphNode* link;
}GraphNode;

typedef struct ArrayListHead{
	GraphNode* head;
}ArrayList;


typedef struct Graph{
	int V;
	ArrayList* listNodes;
}Graph;

void adjacency_matrix();
void adjacency_list();
void display_matrix(int**);

int main(int argc,char* argv[]){
	int selection;
	cout<<"Select the representation form of graph : "<<endl;
	cout<<"1. Adjacency Matrix"<<endl;
	cout<<"2. Adjacency List"<<endl;
	cout<<"Your Choice :: ";
	cin>>selection;
	switch(selection){
		case 1:
				adjacency_matrix();
				break;
		case 2:
				adjacency_list();
				break;
		default:
		 		cout<<"Sorry you have selected a wrong option"<<endl;
	}
	return 0;
}

void adjacency_matrix(){
	//int graph[5][5]; //static allocation

	//A dynamic 2D array is basically an array of pointers to arrays.Remember that anything allocated with new is created on the heap 
	//and must be de-allocated with delete, just keep this in mind and be sure to delete this memory from the heap when you're done with it to prevent leaks

	int** graph = new int*[COL];

	for(int i=0;i<COL;i++){
		graph[i] = new int[ROW];
	}

	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			graph[i][j]=0;
		}
	}

	display_matrix(graph);
}

void display_matrix(int** graph){

	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}

//creating a graph with V vertices
Graph* createGraph(int V){
	
	//dynamically allocate space for a graph
	Graph* graph = (Graph*)malloc(sizeof(Graph));

	//way to access fields of struct through pointer to it
	graph->V = V;

	//allocating space for V heads and storing pointer to them in graph.Note that we can have a pointer to a single struct as well as
	//we can also use that pointer to iterate through a list of structs allocated 
	graph->listNodes = (ArrayListHead*)malloc(V*sizeof(ArrayListHead));

	//initialising all links to lists as null
	for(int i=0;i<V;i++){
		graph->listNodes[i].head = NULL;
	}

	return graph;
}

//function to create a node in graph as new node is added in front of linked list so only dest is required
GraphNode* newGraphNode(int dest){

	GraphNode* newnode = new GraphNode();
	newnode->data = dest;
	newnode -> link = NULL;

	return newnode;
}

void addEdge(Graph* graph,int src,int dest){

	GraphNode* newnode = newGraphNode(dest);

	//add node fron src to destination
	newnode->link = graph->listNodes[src].head;
	graph->listNodes[src].head = newnode;

	//as graph is undirected so create node from dest to src also
	newnode = newGraphNode(src);
	newnode->link = graph->listNodes[dest].head;
	graph->listNodes[dest].head = newnode;
}

void printGraph(Graph* graph){

	cout<<"This Graph has "<<graph->V<<" nodes"<<endl;

	for(int i=0;i<graph->V;i++){

		GraphNode* node = graph->listNodes[i].head;

		cout<<i<<" HEAD -> ";

		while(node!=NULL){

			cout<<node->data<<" ";
			node = node -> link;

		}
		cout<<endl;
	}

}


void adjacency_list(){

	Graph* graph = createGraph(5);

	addEdge(graph,0,1);
	addEdge(graph,2,3);
	addEdge(graph,0,3);
	addEdge(graph,1,4);

	printGraph(graph);

}