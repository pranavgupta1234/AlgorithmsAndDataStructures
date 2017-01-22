#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    node* link;
}node;
void insert_node(node**head ,int data);
void printList(node* head);
void delete_key_ref(node** head,int data);
int main(){

    node* headA = NULL;
    insert_node(&headA,3);
    insert_node(&headA,4);
    insert_node(&headA,5);
    insert_node(&headA,6);

    printList(headA);
    delete_key_ref(&headA,6);
    printList(headA);
	return 0;
}

//remember that doing modifications to local variables will not make any changes in the list for eg. a statement like 
// if temp is a local variable then a statement like temp = temp ->next ; even if temp  point to some location in list is not going to make 
//any changes in list
void delete_key_ref(node** head,int data){
    if(*head==NULL){
    	cout<<"The List is empty, please insert something before deleting , you desperate !!! ;)";
       exit(1);
    }
    node* temp1= *head;
    if(temp1->data==data){
    	*head = (*head)->link;
    	return;
    }
    node* prev;
    while(temp1->data!=data){
    	prev = temp1;
    	temp1=temp1->link;
    }
    prev->link=temp1->link;
}
void insert_node(node** head, int data){

	node *temp= new node();
	temp->link=*head;
	temp->data=data;
	*head=temp;
}
void printList(node* head){
	node * temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<endl;
}