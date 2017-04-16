#include <iostream>
#include "AVL.hpp"
using namespace std;

int main(){

	Trees::AVL<int,int> btree;
	btree.put(10,23);
	btree.put(20,56);
	btree.put(30,34);
	btree.put(40,45);
	btree.put(50,43);
	btree.put(25,46);

	btree.print_pre_order();
	//cout<<btree.size();


	return 0;
	
}