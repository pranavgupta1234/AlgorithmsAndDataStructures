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

void delNafterM(node* head,int n,int m){

	node* curr = head;
	node* prev = NULL;
	node* temp;
	int del = 0;

	for(int i = 0  ; i < m ; i++){
		prev = curr;
		curr = curr -> link;
	}

	temp = prev -> link;

	while(del < n-1){
		delete(temp);
		temp = curr -> link;
		curr = curr -> link;
		del++;
	}

	prev -> link = curr -> link;

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

	delNafterM(list,4,3);

	print(list);

	return 0;
}