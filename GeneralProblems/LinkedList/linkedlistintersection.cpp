#include <iostream>
#include <map>
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

	if(head == NULL){
		return newNode(data);
	}else{

		node* newnode = newNode(data);
		newnode -> link = head;
		return newnode;
	}
}


//O(n2) approach
node* findIntersection(node* l1,node* l2){

	if(l1 == NULL or l2 == NULL){
		return NULL;
	}

	for(node* a = l1 ; a != NULL ; a = a -> link){
		for(node* b = l2 ; b!=NULL ; b  = b -> link){
			if(a == b){
				return a;
			}
		}
	}

	return NULL;
}

//using hash O(m+n) approach but requires extra space
node* findIntersectionEff1(node* l1,node* l2){

	map<node*,int> hash;

	for(node* a = l1 ; a != NULL ; a = a -> link){
		hash[a] = 1;
	}

	for(node* b = l2 ; b!= NULL ; b = b -> link){
		if(hash[b] == 1){
			return b;
		}
	}

	return NULL;
}

int findLength(node* head){

	int count = 0;

	if(head == NULL){
		return 0;
	}else{

		while(head != NULL){
			count++;
			head = head -> link;
		}
	}

	return count;
}

//count difference of size of two linked list and then traverse till the difference and then traverse parallel
// O(m+n) approachs
node* findIntersectionEff2(node* l1,node* l2){

	int larger = 0,diff,i=0;
	
	int len1 = findLength(l1);
	int len2 = findLength(l2);

	if(len1 > len2){
		larger = 1;
	}

	diff = abs(len1 - len2);

	while(i < diff){

		if(larger){
			l1 = l1 -> link;
		}else{
			l2 = l2 -> link;
		}

		i++;
	}

	while( l1 and l2 ){
		if(l1 == l2){
			return l1;
		}else{
			l1 = l1 -> link;
			l2 = l2 -> link;
		}
	}

}

void printList(node* head){
	
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

	list1 = insert(list1,1);
	list1 = insert(list1,2);
	list1 = insert(list1,3);
	list1 = insert(list1,4);
	list1 = insert(list1,5);
	list1 = insert(list1,6);
	
	list2 = insert(list2,9);
	list2 = insert(list2,14);
	list2 = insert(list2,13);
	list2 = insert(list2,21);

	list2 -> link -> link -> link -> link =	list1 -> link ->link; 

	printList(list1);

	printList(list2);

	//cout<<findIntersection(list1,list2) -> data<<endl;

	cout<<findIntersectionEff2(list1,list2) -> data<<endl;
	
	return 0;
}