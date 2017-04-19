#include <iostream>
#include <stdlib.h>
#include "binary_search_tree.hpp"
#include "RBTree.hpp"

using namespace std;

int options(){

	int choice;

	cout<<std::endl;
	cout<<"[1] Insert an element\n";
	cout<<"[2] Delete an element\n";
	cout<<"[3] View an element\n";
	cout<<"[4] Check a key\n";
	cout<<"[5] Find predecessor\n";
	cout<<"[6] Find successor\n";
	cout<<"[7] Find maximum\n";
	cout<<"[8] Find minimum\n";
	cout<<"[9] Print in order\n";
	cout<<"[10] Print pre order\n";
	cout<<"[11] Print post order\n";
	cout<<"[12] Height\n";
	cout<<"[13] Size\n";
	cout<<"[14] Print\n";
	cout<<"[15] Color\n";
	cout<<"[14] Black height\n";
	cout<<"[0] Exit\n";

	cout<<"Enter your choice : ";
	cin>>choice;
	cout<<endl;

	return choice;
}

int main(int arc, char* argv[]){

	Trees::BSTree<int, int> *tree;
	Trees::RBTree<int, int> tree1;
	tree = &tree1; 
	int key;
	int value;

	while(1){
		switch(options()){

			case 1 :	cout<<"Enter key : ";
						cin>>key;
						cout<<"Enter value : ";
						cin>>value;
						tree->put(key, value);
						break;

			case 2 :	cout<<"Enter key : ";
						cin>>key;
						tree->remove(key);
						break;

			case 3 :	cout<<"Enter key : ";
						cin>>key;
						try{
							cout<<"["<<key<<"] : "<<tree->get(key)<<endl;
						}
						catch(const char* err){
							cout<<err<<endl;
						}
						break;

			case 4 :	cout<<"Enter key : ";
						cin>>key;
						if(tree->has(key))
							cout<<"Key exists.\n";
						else
							cout<<"Key doesn't exists.\n";
						break;

			case 5 :	cout<<"Enter key : ";
						cin>>key;
						try{
							cout<<"Predecessor : "<<tree->predecessor(key)<<endl;
						}
						catch(const char* err){
							cout<<err<<endl;
						}
						break;

			case 6 :	cout<<"Enter key : ";
						cin>>key;
						try{
							cout<<"Successor : "<<tree->successor(key)<<endl;
						}
						catch(const char* err){
							cout<<err<<endl;
						}
						break;

			case 7 :	try{
							cout<<"Maximum : "<<tree->maximum()<<endl;
						}
						catch(const char* err){
							cout<<err<<endl;
						}
						break;

			case 8 :	try{
							cout<<"Minimum : "<<tree->minimum()<<endl;
						}
						catch(const char* err){
							cout<<err<<endl;
						}
						break;

			case 9 :	tree->print_in_order();
						cout<<endl;
						break;

			case 10 :	tree->print_pre_order();
						cout<<endl;
						break;

			case 11 :	tree->print_post_order();
						cout<<endl;
						break;

			case 12 :	cout<<tree->getHeight()<<endl;
						break;

			case 13 :	cout<<tree->size()<<endl;
						break;

			case 14 :	tree->print();
						break;
			case 15 :   cout<<"Enter key : ";
						cin>>key;

						tree1.color(key);
						break;
			case 16 :   tree1.blackHeight();
						break;

			case 0 :	exit(EXIT_SUCCESS);

			default :	cout<<"Invalid choice.\n";
		}
	}

	return 0;
}