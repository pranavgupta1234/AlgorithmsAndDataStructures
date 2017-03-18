#include <iostream>
#include <fstream>
#include "queue.hpp"

using namespace std;

int main(){

	int data;
	int offset;
    q::queue<int> queue_adt;						//constructor matching this is called

    //file io
    std::ofstream out;
    std::ifstream in;
    in.open ("input.txt");
    out.open("output.txt",std::ios_base::app);                          // app for append mode

	while(in>>data){														
	    queue_adt.push(data);											//getline(in,data);  to get whole line
    }

    offset = queue_adt.front();

    for(int i=0;i<offset;i++){
    	int popped;
    	popped = queue_adt.pop();
    	queue_adt.push(popped);
    }
    //queue_adt.print_queue();
    int size = queue_adt.size();

    for(int i=0;i<size;i++){
    	out<<queue_adt.pop()<<" ";
    }

	in.close();
	out.close();

	return 0;
}
