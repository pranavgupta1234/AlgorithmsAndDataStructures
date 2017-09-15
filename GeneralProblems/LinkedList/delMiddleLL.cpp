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

node* delMiddle(node* head){

	node* curr = head;
	node* prev = NULL;
	node* temp;
	int count = 0,mid;

	for(node* list = head ; list != NULL ; list = list -> link){
		count++;
	}

	mid = count/2;

	for(int i=0 ; i<mid ; i++){
		prev = curr;
		curr = curr -> link;
	}

	temp = curr -> link;

	delete(curr);

	prev -> link = temp;

	return head;
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

	for(int i=0 ; i<9 ; i++){
		list = insert(list,i+1);
	}

	print(list);

	list = delMiddle(list);

	print(list);

	return 0;
}