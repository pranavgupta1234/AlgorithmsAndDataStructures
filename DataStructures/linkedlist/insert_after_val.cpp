#include <bits/stdc++.h>
using namespace std;
typedef struct node{
     int data;
     node* link;
}node;

void insert_after_byref(node** head,int after,int data);
node* insert_after(node* head,int after,int data);
void printList(node* head);
int main(){
	node* headA = NULL;
    insert_after_byref(&headA,3,3);
    insert_after_byref(&headA,3,6);
    insert_after_byref(&headA,3,5);
    insert_after_byref(&headA,5,7);
    printList(headA);
    headA = insert_after(headA,7,89);
	printList(headA);
	return 0;
}

void insert_after_byref(node** head,int after,int data){
	if(*head == NULL){
		cout<<"The list is empty so adding this data element which you wanted to insert after"<<endl;
		node *temp = new node();
		temp->data = data;
		temp->link = NULL;
		*head=temp; 
	}
	else{
		node* temp1 = *head;
		while(temp1->data!=after){
            temp1 = temp1->link;
		} 
		node* temp = new node();
		temp->data = data;
		temp->link= temp1->link;
        temp1->link = temp;
	}
}
node* insert_after(node* head,int after,int data){
	node* head_to_return = head;
    if(head == NULL){
		cout<<"The list is empty so adding this data element which you wanted to insert after"<<endl;
		node *temp = new node();
		temp->data = data;
		temp->link = NULL;
		return temp; 
	}
	else{
		node* temp1 = head;
		while(temp1->data!=after){
            temp1 = temp1->link;
		} 
		node* temp = new node();
		temp->data = data;
		temp->link= temp1->link;
        temp1->link = temp;
        return head_to_return;
	}
}
void printList(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
         temp=temp->link;
	}
	cout<<endl;
}