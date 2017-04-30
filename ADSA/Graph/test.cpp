#include <iostream>
#include "DirectedGraph.hpp"
using namespace std;

int main(){

	DirectedGraph graph(5,'m');

	graph.add(2,3);
	graph.add(1,3);
	graph.add(3,4);
	graph.add(2,4);

	graph.print();


	return 0;
}