#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    node* link;
}node;

void insert_node(node** head,int data);
node* insert_node_return(node* head,int data);
void printList(node* head);
int main(){
	node *headA=NULL;
	node *headB=NULL;


    headA=insert_node_return(headA,2);
    headA=insert_node_return(headA,3);
    headA=insert_node_return(headA,4);
    
    printList(headA);

    //pass by ref to add
    insert_node(&headA,5);
    printList(headA);
	return 0;
}
//use when you pass head of list by reference and not by value because head in this a local variable of this function 
//and modification of head = temp will not effect list in main()
// O(1)
void insert_node(node** head, int data){

	node *temp= new node();
	temp->link=*head;
	temp->data=data;
	*head=temp;
}

//use when you pass head by value and not by reference then node's location created in heap is returned back to head in main
//O(1)
node* insert_node_return(node* head,int data){
	node * temp = new node();
	temp->link=head;
	temp->data=data;
	return temp;
}

void printList(node* head){
	node * temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<endl;
}