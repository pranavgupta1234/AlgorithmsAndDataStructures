#include <iostream>
#include "binary_search_tree.hpp"
using namespace std;

int main(){

	Trees::BSTree<int,int> btree;
	btree.put(5,23);
	btree.put(4,56);
	btree.put(6,34);
	btree.put(9,45);
	btree.put(2,43);
	btree.put(3,46);
	btree.put(12,244);
	btree.put(10,435);

	//btree.print_in_order();
	cout<<btree.successor(5);


	return 0;
	
}