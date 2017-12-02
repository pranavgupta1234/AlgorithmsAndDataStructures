#include <iostream>
#include <vector>

using namespace std;

//in place sorting
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

node* mergeSorted(node* list1,node* list2){

	if(list1 == NULL){
		return list2;
	}

	if(list2 == NULL){
		return list1;
	}

	if(list1 -> data < list2 -> data){
		list1 -> link = mergeSorted(list1 -> link,list2);
		return list1;
	}else{
		list2 -> link = mergeSorted(list1,list2->link);
		return list2;
	}
}

int main(){
	
	node* list = NULL;
	list = insert(list,56);
	list = insert(list,45);
	list = insert(list,12);
	list = insert(list,3);		
	list = insert(list,1);

	node* list1 = NULL;
	list1 = insert(list1,267);
	list1 = insert(list1,57);
	list1 = insert(list1,23);
	list1 = insert(list1,4);		
	list1 = insert(list1,2);

	node* listm = mergeSorted(list,list1);

	print(listm);
	return 0;
}