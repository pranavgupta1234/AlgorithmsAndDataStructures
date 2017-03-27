#include <iostream>
#include <stdlib.h>
#include <string>

#include "DoubleHashMap2.hpp"

int main(int argc,char* argv[]){

	int N, M, K, input, max;

	if(argc<=3){
		std::cout<<"Too few arguments..,first parameter is blocks in main memory,second is blocks in cache memory,third is size of blocks"<<std::endl;
		exit(0);
	}

	M = atoi(argv[1]);
	N = atoi(argv[2]);
	K = atoi(argv[3]);

	if(K > M || K > N){
		std::cout<<"Not Possible\n";
		exit(0);
	}

	M = M/K, N = N/K;

	cs202::DoubleHashMap<int, int> cache(N);
	cs202::LinearList<pair<int, int> > counter(N);

	while(1){

		std::cout<<"Enter main memory address (-1 for exit): ";
		std::cin>>input;


		if(input < 0)
			exit(EXIT_SUCCESS);

		input /= K;

		if(input >= M){
			std::cout<<"** Memory address does not exists.\n";
			exit(EXIT_SUCCESS);
		}

		if(counter.size() == N && !cache.has(input)){
			max = 0;
			for(int i = 0; i < counter.size(); i++){
				if(counter[i].value() > counter[max].value()){
					max = i;
				}
			}

			cache.remove(counter[max].key());
			counter.erase_pos(max);
		}

		if(!cache.has(input)){
			counter.push_back(pair<int, int>(input, 0));
			cache[input] = input;
		}

		for(int i = 0; i < counter.size(); i++){
			if(counter[i].key() != input){
				counter[i].value() += 1;
			}
			else
				counter[i].value() = 0;
		}

		std::cout<<"CacheMemory \t: CacheCounters\n";
		for(int i = 0; i < counter.size(); i++){
			
			std::cout<<"MainMemory["<<cache[counter[i].key()]<<"] \t : "<<counter[i].value()<<std::endl;
		}

	}
	return 0;
}