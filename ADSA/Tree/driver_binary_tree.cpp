#include <iostream>
#include <stdlib.h>
#include "binary_tree.hpp"

int options(){

	int choice;

	std::cout<<std::endl;
	std::cout<<"[1] Insert an element"<<std::endl;
	std::cout<<"[2] Delete an element"<<std::endl;
	std::cout<<"[3] View an element"<<std::endl;
	std::cout<<"[4] Check a key "<<std::endl;
	std::cout<<"[5] Print In Order"<<std::endl;
	std::cout<<"[6] Print Pre Order"<<std::endl;
	std::cout<<"[7] Print Post Order"<<std::endl;
	std::cout<<"[8] Maximum"<<std::endl;
	std::cout<<"[9] Minimum"<<std::endl;
	std::cout<<"[10] Size"<<std::endl;
	std::cout<<"[0] Exit"<<std::endl;

	std::cout<<"Enter your choice : ";
	std::cin>>choice;
	std::cout<<std::endl;

	return choice;
}

int main(int argc, char* argv[]){

	Trees::BinaryTree<int, int> btree;

	int key;
	int value;

	while(true){

		switch(options()){

			case 1	:	std::cout<<"Enter key : ";
						std::cin>>key;
						std::cout<<"Enter value : ";
						std::cin>>value;
						btree.put(key,value);
						break;

			case 2	:	std::cout<<"Enter key : ";
						std::cin>>key;
						btree.remove(key);
						break;

			case 3 	:	std::cout<<"Enter key : ";
						std::cin>>key;
						try{
							std::cout<<btree.get(key)<<std::endl;
						}
						catch(const char* err){
							std::cerr<<err<<std::endl;
						}
						break;

			case 4	:	std::cout<<"Enter key : ";
						std::cin>>key;
						std::cout<<(btree.has(key) ? "Exists." : "Does not exist.")<<std::endl;
						break;

			case 5	:	btree.print_in_order();
						break;


			case 6	:	btree.print_pre_order();
						break;

			case 7	:	btree.print_post_order();
						break;

			case 8	:	std::cout<<"Maximum : "<<btree.maximum()<<std::endl;
						break;


			case 9	:	std::cout<<"Minimum : "<<btree.minimum()<<std::endl;
						break;


			case 10	:	std::cout<<"Size : "<<btree.size()<<std::endl;
						break;																																				

			case 0	:	exit(EXIT_SUCCESS);

			default	:	std::cout<<"Invalid choice."<<std::endl;
						break;
		}
	}

	return 0;
}