#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    node* link;
}node;
void insert(node**,int);
void printList(node*);
int get_nth_node(node*,int);
int main(){
	node* headA=NULL;
    insert(&headA,2);
    insert(&headA,4);
    insert(&headA,6);
    for(int i=0;i<5;i++){
    	insert(&headA,10*i);
    }
    printList(headA);
	cout<<"Enter position of node"<<endl;
    int n;
	cin>>n;
	cout<<get_nth_node(headA,n)<<endl;
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
int get_nth_node(node* head,int n){
	if(head==NULL){
		cout<<"List is empty"<<endl;
		exit(1);
	}
	if(n==0){
		cout<<"This is not a valid location, locations start from 1"<<endl;
		exit(1);
	}
	for(int i=0;i<n-1;i++){
		if(head->link==NULL){
			cout<<"No such location exist in list"<<endl;
			exit(1);
		}
		head=head->link;
	}
	return head->data;
}