#include <iostream>
#include <math.h>

using namespace std;

typedef struct node{
	int data;
	node* link;
}node;

node* newNode(int data){
	node* newnode = new node();
	newnode -> data = data;
	newnode -> link = NULL;
	return newnode;
}

node* insert(node* head,int data){

	if(head == NULL){
		return newNode(data);
	}else{
		node* newnode = newNode(data);
		newnode -> link = head;
		return newnode;
	}	
}

node* revList(node* head){

	if(head == NULL){
		return NULL;
	}else if(head -> link == NULL){
		return head;
	}else{

		node* res = revList(head -> link);
		head -> link -> link = head;
		head -> link = NULL;

		return res;
	}
}

void print(node *head){

	if(head == NULL){
		return;
	}else{
		while(head != NULL){
			cout<<head -> data<<" ";
			head = head -> link; 
		}
	}

	cout<<endl;
}

node* sum(node* num1,node* num2){

	node* sum_list = NULL;
	int carry = 0,s1 = 0,s2 = 0;
	node* head1 = num1;
	node* head2 = num2;

	while(head1 != NULL or head2 != NULL){

		head1 != NULL ? s1 = head1 -> data : s1 = 0;
		head2 != NULL ? s2 = head2 -> data : s2 = 0;
		
		int s = s1 + s2;
		//cout<<s<<endl;
		sum_list = insert(sum_list,((carry + s)%10));
		carry = (carry+s)/10;
		//print(sum_list);

		if(head1 != NULL){
			head1 = head1 -> link;			
		}else{
			head1  = NULL;
		}

		if(head2 != NULL){
			head2 = head2 -> link;			
		}else{
			head2  = NULL;
		}

		//cout<<s1<<" "<<s2<<endl;
	}

	sum_list = revList(sum_list);

	return sum_list;
}

int main(){
	
	node* list1 = NULL;
	node* list2 = NULL;

	for(int i=3 ; i<5 ; i++){
		list1 = insert(list1,i+1);
	}

	for(int i=2 ; i<5 ; i++){
		list2 = insert(list2,i+1);
	}

	print(list1);

	print(list2);

	node* sum_list = sum(list1,list2);

	print(sum_list);
	
	return 0;
}