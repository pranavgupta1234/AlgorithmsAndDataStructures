#include <iostream>
#include <vector>
#include <cstring>
#include <string>

#define ALPHABET_SIZE 26

using namespace std;

typedef struct node{
	char* refs[ALPHABET_SIZE];
	bool end;
}trieNode;

trieNode* newNode(){
	trieNode* newtrienode = new trieNode();
	for(int i=0 ; i<ALPHABET_SIZE ; i++){
		trieNode -> refs[i] = NULL;
	}
	trieNode -> end = false;
	return trieNode;
}

void insert(trieNode* root,string key){
	trieNode* rootNode = root;
	for(int i=0 ; i<key.length() ; i++){
		int val = key[i] - 'a';
		if(root -> refs[val] != NULL){
			root = root -> refs[]
		}
	}
}

void countExact(trieNode* root,string key){
	
}

int main(){



	return 0;
}