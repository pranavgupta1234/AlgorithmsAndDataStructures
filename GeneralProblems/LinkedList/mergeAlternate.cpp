#include <iostream>

using namespace std;

typedef struct node{
	int data;
	node* link;
}node;

node* newNode(int data){
	node* newnode = new node();
	newnode -> data = data;
	newnode -> link = NULL;
	return newnode;
}

node* insert(node* head,int data){

	if(head == NULL){
		return newNode(data);
	}else{
		node* newnode = newNode(data);
		newnode -> link = head;
		return newnode;
	}	
}

node* MergeAlternate(node* list1,node* list2){
	node* 
}

void print(node *head){

	if(head == NULL){
		return;
	}else{
		while(head != NULL){
			cout<<head -> data<<" ";
			head = head -> link; 
		}
	}

	cout<<endl;
}

int main(){
	
	node* list1 = NULL;
	node* list2 = NULL;

	for(int i=0 ; i<5 ; i++){
		list1 = insert(list1,i+1);
	}

	for(int i=5 ; i<10 ; i++){
		list2 = insert(list2,i+1);
	}

	print(list);

	list = delMiddle(list);

	print(list);

	return 0;
}