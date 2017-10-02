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

node* startingLoop(node* head,node* inloop){
	if(head and inloop){
		while(head and inloop){
			if(head == inloop){
				return head;
			}
			head = head -> link;
			inloop = inloop -> link;
		}		
	}
	return NULL;
}

node* detectLoop(node* head){

	node* slow = head;
	node* fast = head;

	while(slow != NULL and fast != NULL and fast -> link != NULL){

		slow = slow -> link;
		fast = fast -> link -> link;

		if(slow == fast){
			return startingLoop(head,fast);
		}	
	}
}

void detectAndRemoveUtil(node* head,node* inloop){
	node* prev = NULL;
	if(head and inloop){
		while(head != inloop){
			prev = inloop;
			inloop = inloop -> link;
			head = head -> link;
		}
	}

	prev -> link = NULL;
	return ;
}

void detectAndRemove(node* head){
	node* slow = head;
	node* fast = head;
	while(slow and fast and fast -> link){
		slow = slow -> link;
		fast = fast -> link -> link;
		if(slow == fast){
			return detectAndRemoveUtil(head,fast);
		}
	}
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

	node* end = list;

	while(end -> link != NULL){
		end = end -> link;
	}
	
	end -> link = list -> link -> link -> link;

	//cout<<detectLoop(list) -> data<<endl;
	//print(list);
	detectAndRemove(list);

	print(list);
	return 0;
}