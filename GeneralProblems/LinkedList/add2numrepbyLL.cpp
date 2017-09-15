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

//not a correct way to do because numbers can be quite large

node* sum(node* num1,node* num2){

	int n1=0,n2=0;
	int count1=0,count2=0;

	for(node* head = num1 ; head != NULL ; head = head -> link){
		count1++;
	}

	for(node* head = num2 ; head != NULL ; head = head -> link){
		count2++;
	}

	//cout<<count1<<" "<<count2<<endl;
	int c1 = 0;
	int c2 = 0;

	while(c1 < count1){
		n1 += pow(10,c1)*(num1 -> data);
		num1 = num1 -> link;
		c1++;
	}

	while(c2 < count2){
		n2 += pow(10,c2)*(num2 -> data);
		num2 = num2 -> link;
		c2++;
	}

	//cout<<n1<<" "<<n2<<endl;

	int s = n1 + n2;
	int copysum = s;
	int digits_copy=0;
	while(copysum){
		copysum /= 10;
		digits_copy++;
	}

	node* sumnum = NULL;

	//pow return double
	while(digits_copy){
		int c = s;
		c = c/(int)pow(10,digits_copy-1);
		sumnum = insert(sumnum,c%10);
		c = s;
		digits_copy--;
	}

	return sumnum;
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

	node* sumofnum = sum(list1,list2);

	print(sumofnum);
	return 0;
}