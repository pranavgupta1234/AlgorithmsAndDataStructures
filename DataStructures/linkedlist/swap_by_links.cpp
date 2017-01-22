#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    node* link;
}node;
void insert(node**,int);
void printList(node*);
void swap_by_links(node**,int,int);
int main(){
	node* headA=NULL;
	insert(&headA,4);
    insert(&headA,7);
    insert(&headA,9);
    insert(&headA,3);
    insert(&headA,2);
    insert(&headA,8);
    printList(headA);
    swap_by_links(&headA,4,8);
    printList(headA);
	return 0;
}
void insert (node** head,int data){
	node* temp = new node();
	temp->data=data;
	temp->link=*head;
	*head=temp;
}
void printList(node* head){
   while(head!=NULL){
   	cout<<head->data<<" ";
   	head=head->link;
   }
   cout<<endl;
}
void swap_by_links(node** head,int a,int b){
    node* currX;
    node* prevX;
    node* currY;
    node* prevY;
    
    if(a==b){
    	cout<<"Same nodes, nothing to swap"<<endl;
    	exit(1);
    }

    prevX=NULL;
    currX=*head;
    while(currX && currX->data!=a){
    	prevX=currX;
    	currX=currX->link;
    }

    prevY=NULL;
    currY=*head;
    while(currY && currY->data!= b){
    	prevY=currY;
    	currY=currY->link;
    }
    if(currX==NULL || currY== NULL){
    	cout<<"Field not found"<<endl;
    	exit(1);
    }
    if(prevX!=NULL)
    	prevX->link=currY;
    else
    	*head=currY;

    if(prevY!=NULL)
    	prevY->link=currX;
    else
    	*head=currX;

    node* temp = currY->link;
    currY->link=currX->link;
    currX->link=temp;

}