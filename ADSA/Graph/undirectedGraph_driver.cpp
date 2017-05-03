#include <iostream>
#include <fstream>
#include <string>
#include "UndirectedGraph.hpp"
using namespace std;

int options(){

	int choice;

	std::cout<<std::endl;
	std::cout<<"[1] Insert an Edge"<<std::endl;
	std::cout<<"[2] Check for an Edge "<<std::endl;
	std::cout<<"[3] Remove An Edge"<<std::endl;
	std::cout<<"[4] No of Edges "<<std::endl;
	std::cout<<"[5] No of Vertices"<<std::endl;
	std::cout<<"[6] Degree of any vertex"<<std::endl;
	std::cout<<"[7] BFS "<<std::endl;
	std::cout<<"[8] DFS"<<std::endl;
	std::cout<<"[0] Exit"<<std::endl;

	std::cout<<"Enter your choice : ";
	std::cin>>choice;
	std::cout<<std::endl;

	return choice;
}

void print_it(int& a){
	cout<<a<<" ";
}

int main(int argc, char* argv[]){

	int marker;
	int vertex,j=0,total_points;
	int vertices;
	char rep;
	string file_name;
	cout<<"Enter the number of vertices in the graph"<<endl;
	cin>>vertices;
	cout<<"Enter the internal representation for your graph (this affects complexities :) , l for list and m for matrix representation"<<endl;
	cin>>rep;
	if(rep != 'm' and rep != 'l'){
		cout<<"Sorry wrong choice :( "<<endl;
		exit(0);
	}
	UndirectedGraph graph(vertices,rep);

	cout<<"Do you want to give input from file : (Press 1 for yes and 0 for custom input)"<<endl;
	cin>>marker;

	total_points = vertices*vertices;

	if(marker == 1){

		cout<<"Enter the file name"<<endl;
		cin>>file_name;
		ifstream myfile;
    	myfile.open(file_name);
    	if(myfile.is_open()){
    		while(total_points--){

    		    for(int i=0 ; i<vertices ; i++){
    			myfile >> vertex;
    				if(vertex == 1){
    					graph.add(j,i);
    				}
    			}	
    			j++;	
    		}

    	}

	}

	int v1;
	int v2;

	while(true){

		switch(options()){

			case 1	:	std::cout<<"Enter starting vertex : ";
						std::cin>>v1;
						std::cout<<"Enter ending vertex : ";
						std::cin>>v2;
						graph.add(v1,v2);
						break;

			case 2	:	std::cout<<"Enter starting vertex : ";
						std::cin>>v1;
						std::cout<<"Enter ending vertex : ";
						std::cin>>v2;
						cout<<(graph.edgeExists(v1,v2) ? "Exists" : "Doesn't Exist");
						break;

			case 3 	:	std::cout<<"Enter starting vertex : ";
						std::cin>>v1;
						std::cout<<"Enter ending vertex : ";
						std::cin>>v2;
						graph.remove(v1,v2);
						break;

			case 4	:	std::cout<<"No of Edges : ";
						std::cout<<graph.edges()<<endl;
						break;

			case 5	:	std::cout<<"No of Vertices : ";
						std::cout<<graph.vertices()<<endl;
						break;


			case 6	:	std::cout<<"Enter the vertex : ";
						cin>>v1;
						std::cout<<graph.degree(v1)<<endl;
						break;

			case 7	:	graph.bfs(&print_it);
						break;

			case 8	:	graph.dfs(&print_it);
						break;																																				

			case 0	:	exit(EXIT_SUCCESS);

			default	:	std::cout<<"Invalid choice."<<std::endl;
						break;
		}
	}

	return 0;
}