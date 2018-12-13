#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* next;
};

node* newNode(int data){
    node* n = new node();
    n -> data = data;
    n -> next = NULL;
    return n;
}

node* insert(node* head,int data){
    if(head == NULL) return newNode(data);
    node* n = newNode(data);
    n -> next = head;
    return n;
}

void insert2(node*& head,int data){
    if(head == NULL) head = newNode(data);
    node* n = newNode(data);
    n -> next = head;
    head = n;
}

void print(node* head){
    while(head != NULL){
        cout<<head -> data<<" ";
        head = head -> next;
    }
}

int detectloop(node *list){
    node* head1 = list;
    node* head2 = list;
    while(head1 != NULL and head2 != NULL and head2-> next != NULL){
        head1 = head1 -> next;
        head2 = head2 -> next -> next;
        if(head1 == head2) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    node* list = NULL;
    list = insert(list,1);
    list = insert(list,2);
    list = insert(list,3);
    list = insert(list,4);
    list = insert(list,5);
    list = insert(list,6);
    print(list);
    cout<<endl;
    insert2(list,7);
    print(list);
    cout<<endl;
    return 0;
}