#ifndef LIST_HPP
#define LIST_HPP 1

namespace ll{

//declare it before node because we want to make it friend of node
template<class T> class list;
//make it friend so that list can access the private fields of node
template<class T>
class node{
    friend list<T>;
    private: 
    T data;
    node<T>* link;
};

template<class T>
class list{
/*typedef struct node{
    T data;
    node* link;
}node;*/

private:

    node<T>* head;
    int size;

public:
    /*
    * Primary contructor.
    * Should construct an empty list.
    * Size of the created list should be zero.
    */
    list();
    /*
    * Seondary constructor.
    * Creates a new list which is a copy of the provided list.
    */
    list(list<T> & x);
    /*
    * Destructor.
    * Frees all the memory acquired by the list.
    */
    ~list();
    /*
    * adds value at the end of the list.
    */
    void append(const T& value);
    /*
    * Returns the length of the list.
    */
    inline int length();
    /*
    * Returns a boolean indicating whether the list is empty.
    */
    inline bool empty();
    /*
    * Adds a value to the front of the list.
    */
    void insert(const T& value);
    /*
    * Removes the first occurence of the value from list.
    */
    void remove(const T & x);
    /*
    * Appends the given list x at the end of the current list.
    */
    void append(list<T>& x);
    /*
    *prints the list
    */
    void printList();
    /*
    * return the first element in the list
    */
    T top_element();

    //removes first element in the list
    void remove_first();
};

template<class T>
list<T> :: list(){
    head = NULL;
    size = 0;
}

template<class T>
list<T> :: list(list<T> & x){
    
    int s = x.length();

    head = NULL;
    size = s;

    

    for(int i=0;i<s;i++){

        T value = x.top_element();
        x.remove_first();
        node<T>* newnode = new node<T>();

        if(head==NULL){
            newnode -> data = value;
            newnode -> link = NULL;
            head = newnode;        
        }
        else{

            node<T>* temp_head = head;
            while(temp_head->link!=NULL){
                temp_head = temp_head ->link;
            }

            newnode -> data = value;
            newnode -> link = NULL;
            temp_head -> link = newnode;
        }
    }


}

template<class T>
list<T> :: ~list(){
    delete head;
}

template<class T>
void list<T> :: append(const T& value){

    node<T>* newnode = new node<T>();                             //instantiates the node object                // only needed with struct  new node();

    if(head==NULL){
        newnode->data = value;
        newnode->link = NULL;
        head = newnode;        
        //increment size
        size = size + 1;
    }
    else{

        node<T>* temp_head = head;
        while(temp_head->link!=NULL){
            temp_head = temp_head ->link;
        }

        newnode -> data = value;
        newnode -> link = NULL;
        temp_head -> link = newnode;

        //increment size
        size = size + 1;
    }

}

template<class T>
int list<T> :: length(){

    if(head==NULL){
        return 0;
    }

    return size;
}

template<class T>
bool list<T> :: empty(){

    if(head==NULL){
        return true;
    }
    return false;
}

template<class T>
void list<T> :: insert(const T& value){

    node<T>* newnode = new node<T>();
    //we use const because to make sure that the value which user wants to insert is not modified here

    newnode->data = value;
    newnode->link = head;
    head = newnode;

    //increment size
    size += 1;
}

template<class T>
void list<T> :: remove(const T & x){

    if(head!=NULL){

        node<T>* temp_head = head;
        node<T>* prev;

        if(head->data==x){
            head = head ->link;
            size = size-1;
            return ;
        }

        while(temp_head->data!=x){
            prev = temp_head;
            temp_head = temp_head->link;
        }
        prev->link = temp_head->link;
    }
    size = size-1;
}

template<class T>
void list<T> :: printList(){

    node<T>* temp = head;

    while(temp!=NULL){
        std::cout<<temp->data<<" ";
        temp = temp -> link;
    }
    std::cout<<std::endl;
}

template<class T>
void list<T> :: append(list<T>& x){

    int s = x.length();

    size = size + s;

    for(int i=0;i<s;i++){

        T value = x.top_element();
        x.remove_first();
        node<T>* newnode = new node<T>();

        if(head==NULL){
            newnode -> data = value;
            newnode -> link = NULL;
            head = newnode;        
        }
        else{

            node<T>* temp_head = head;
            while(temp_head->link!=NULL){
                temp_head = temp_head ->link;
            }

            newnode -> data = value;
            newnode -> link = NULL;
            temp_head -> link = newnode;
        }
    }
}

template<class T>
T list<T> :: top_element(){
    if(head!=NULL){
        return head->data;
    }
}

template<class T>
void list<T> :: remove_first(){
    node<T>* to_remove = head;
    head = head->link;
    delete to_remove;
    size = size -1;
}

//end of namespace    
}

#endif