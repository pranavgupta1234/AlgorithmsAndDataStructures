#include <iostream>
#include <stdlib.h>
#include "PriorityQueue.hpp"

int options(){

	int choice;

	std::cout<<std::endl;
	std::cout<<"[1] Insert"<<std::endl;
	std::cout<<"[2] Minimum"<<std::endl;
	std::cout<<"[3] Extract Minimum"<<std::endl;
	std::cout<<"[4] Heap Size"<<std::endl;
	std::cout<<"[5] Empty"<<std::endl;


	std::cout<<"Enter your choice : ";
	std::cin>>choice;
	std::cout<<std::endl;

	return choice;
}

int main(int argc, char* argv[]){

	cs202::MinPriorityQueue<int> queue;

	int key;

	while(true){

		switch(options()){

			case 1	:	std::cout<<"Enter key : ";
						std::cin>>key;
						queue.insert(key);
						break;

			case 2	:	std::cout<<"Minimum : ";
						std::cout<<queue.minimum();
						break;

			case 3 	:	std::cout<<"Extract Minimum : ";
						std::cout<<queue.extract_min();
						break;

			case 4	:	std::cout<<"Heap Size : ";
						std::cout<<queue.size_heap()<<std::endl;
						break;

			case 5	:	std::cout<<"Is Empty : ";
						std::cout<<queue.empty()<<std::endl;
						break;

			case 0	:	exit(EXIT_SUCCESS);

			default	:	std::cout<<"Invalid choice."<<std::endl;
						break;
		}
	}

	return 0;
}