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

node* revk(node* head,int k){
	node* current = head;
	node* next = NULL;
	node* prev = NULL;
	int count = 0;
	while(current != NULL and count < k){
		next = current -> link;
		current -> link = prev;
		prev = current;
		current = next;
		count++;
	}
	if(next != NULL){
		head -> link = revk(next,k);
		//cout<<head -> data<<endl;
	}
	return prev;
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
	node* list = NULL;
	for(int i=0 ; i<10 ; i++){
		list = insert(list,i+1);
	}
	print(list);
	list = revk(list,5);
	print(list);
	return 0;
}