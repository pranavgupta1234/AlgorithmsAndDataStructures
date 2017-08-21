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

	if(!head){
		return newNode(data);
	}

	node* newnode = newNode(data);
	newnode -> link = head;
	return newnode;

}

void print(node* head){

	while(head!=NULL){
		cout<<head -> data<<" ";
		head = head -> link;
	}
	cout<<endl;
}

node* merge(node* list1,node* list2){

	if(list1 == NULL or list2 == NULL){
		return NULL;
	}

	if(list1 -> data > list2 -> data){
		return merge(list1,list2->link);
	}

	if(list1 -> data < list2 -> data){
		return merge(list1->link,list2);
	}

	

}

int main(){
	
	node* list = NULL;
	list = insert(list,1);
	list = insert(list,3);
	list = insert(list,6);
	list = insert(list,12);		
	list = insert(list,14);

	node* list1 = NULL;
	list1 = insert(list1,2);
	list1 = insert(list1,7);
	list1 = insert(list1,9);
	list1 = insert(list1,34);		
	list1 = insert(list1,67);

	node* listm = merge(list,list1);

	print(listm);
	return 0;
}