#include <iostream>
#include <vector>

using namespace std;

struct node{

	int data;
	node* link;

};


node* newNode(int data){

	node* newnode = new node();
	newnode -> data = data;
	newnode -> link = NULL;
	return newnode;

}

node* insert(node* head,int data){

	if(head == NULL){
		return newNode(data);
	}

	node* temp = newNode(data);
	temp -> link = head;
	head = temp;
	return head;

}

void printList(node* head){

	if(head == NULL){
		cout<<"List Is Empty"<<endl;
		return ;
	}

	while(head != NULL){
		cout<<head -> data<<" ";
		head = head -> link;
	}
	cout<<endl;
}

node* freeList(node* head){

	node* temp = head;

	while(head != NULL){
		temp = head -> link;
		delete(head);
		head = temp;
	}

	return NULL;
}

node* deleteK(node* head,int k){

	if(head == NULL){
		cout<<"List is Empty"<<endl;
		return NULL;
	}

	if(k==1){
		return freeList(head);
	}

	node* ptr = head;
	node* prev = head;
	int count = 0;

	while(ptr != NULL){

		count++;

		if(count == k){

			delete(prev -> link);
			prev -> link = ptr -> link;
			count = 0;
		}

		if(count != 0){
			prev = ptr;
		}

		ptr = prev -> link;

	}

	return head;

}

int main(){
	
	node* listA = NULL;

	listA = insert(listA,1);
	listA = insert(listA,2);
	listA = insert(listA,3);
	listA = insert(listA,4);
	listA = insert(listA,5);
	listA = insert(listA,6);		

	printList(listA);

	deleteK(listA,2);

	printList(listA);


	return 0;
}