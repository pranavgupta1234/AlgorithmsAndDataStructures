#include <iostream>
#define ROW 5
#define COL 5

using namespace std;

typedef struct GraphNode{
	int data;
	struct GraphNode* link;
}GraphNode;

typedef struct ArrayList{
	GraphNode* list;
}ArrayList;

typedef struct Graph{
	int V;
	ArrayList* graph;

}Graph;

void adjacency_matrix();
void adjacency_list();
void display_matrix(int**);


int main(int argc,char* argv[]){
	int selection;
	cout<<"Select the representation form of graph : "<<endl;
	cout<<"1. Adjacency Matrix"<<endl;
	cout<<"2. Adjacency List"<<endl;
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

Graph* createGraph(int V){
	Graph graph = 
}
void adjacency_list(){



}