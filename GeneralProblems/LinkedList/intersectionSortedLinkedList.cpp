#include <iostream>

using namespace std;

struct node{
	int data;
	node* next;
};

node* newNode(int data){

	node* newnode = new node();
	newnode -> data = data;
	newnode -> next = NULL;

	return newnode;
}

node* insert(node* head,int data){

	if(head == NULL){
		return newNode(data);
	}

	node* newnode = newNode(data);
	newnode -> next = head;
	return newnode;
}

void print(node* head){

	if(head == NULL){
		return;
	}else{

		while(head != NULL){

			cout<<head -> data<<" ";
			head = head -> next;
		}
	}
	cout<<endl;
}

node* intersection(node* list1,node* list2){

	if(list1 == NULL or list2 == NULL){
		return NULL;
	}

	if(list1 -> data < list2 -> data){
		return intersection(list1,list2->next);
	}

	if(list1 -> data > list2 -> data){
		return intersection(list1->next,list2);
	}

	node* temp = new node();
	temp -> data = list1 -> data;	
	//cout<<temp -> data<<endl;
	temp -> next = 	intersection(list1 -> next,list2 -> next);
	return temp;

}

int main(){

	node* listA = NULL;	
	listA = insert(listA,1);
	listA = insert(listA,2);
	listA = insert(listA,3);
	listA = insert(listA,4);
	listA = insert(listA,5);

	node* listB = NULL;	
	listB = insert(listB,1);
	listB = insert(listB,3);
	listB = insert(listB,5);

	print(listA);
	print(listB);
	node* listC = intersection(listA,listB);	
	print(listC);
	return 0;
}