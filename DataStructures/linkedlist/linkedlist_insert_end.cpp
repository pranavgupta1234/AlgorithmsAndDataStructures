#include <bits/stdc++.h>
using namespace std;
typedef struct node{
     int data;
     node* link;
}node;

void insert_end_ref(node** head,int data);
node* insert_end(node* head, int data);
void printList(node* head);
int main(){
    node *headA=NULL;
    insert_end_ref(&headA,2);
    insert_end_ref(&headA,3);
    insert_end_ref(&headA,67);
    
    printList(headA);
    headA=insert_end(headA,45);
    printList(headA);
	return 0;
}

//uses head passed by ref
//Always remember once you pass head into your these function they are able to change values and links in linked list
//the local variable is mostly head so any modifications to head must be either returned or should be modified as when passed by reference
void insert_end_ref(node** head,int data){
	if(*head==NULL){
        node* temp = new node();
        temp->data = data;
        temp->link = NULL;
        *head = temp;
	}
	else{
		node *temp1 = *head;
			while(temp1->link!=NULL){
				temp1=temp1->link;
	    	}
		node *temp = new node();
		temp->data = data;
	    temp->link = NULL;

	    temp1->link=temp;
    }
}

node* insert_end(node* head,int data){
	node* head_to_return = head;
	if(head==NULL){
        node* temp = new node();
        temp->data = data;
        temp->link = NULL;
        return temp;
	}
	else{
		node *temp1 = head;
			while(temp1->link!=NULL){
				temp1=temp1->link;
	    	}
		node *temp = new node();
		temp->data = data;
	    temp->link = NULL;

	    temp1->link=temp;
    }
    return head_to_return;
}

void printList(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
         temp=temp->link;
	}
	cout<<endl;
}