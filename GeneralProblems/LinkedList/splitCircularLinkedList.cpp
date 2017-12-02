#include <iostream>
#include <vector>

using namespace std;

struct node*{
	int data;
	node* next;
};

node* newNode(int data){
	node* newnode = new node();
	newnode -> data = data;
	newnode ->	next = NULL; 
	return newnode;
}

int main(){
	


	return 0;
}