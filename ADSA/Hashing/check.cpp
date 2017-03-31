#include <iostream>
#include <string>
#include <climits>
#include "ChainedMap.hpp"
#include <string>

using namespace std;

int main(){

	CM::ChainedMap<int,int> map;
	//map.setDefaultValues("","","emp");
	
	for(int i=0;i<100000;i++){
		map.put(i,i+1);		
	}

	map.printTable();

	return 0;
}