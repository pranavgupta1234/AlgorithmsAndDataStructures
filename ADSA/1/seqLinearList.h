#ifndef SEQLINEARLIST_H
#define SEQLINEARLIST_H
#include <iostream>
#include <string.h>

/* Templates are the foundation of generic programming, which involves writing code in a
 way that is independent of any particular type.
*/

 /** All defination of function in template should be defined in the same header file
  i.e we can't "define" the function declaration here (also called interface) and 
 function definitions in cpp file 
 */

 //Also we can define function definitions out side the class using scope resolution operator

 //structure of defining a template is also shown in this program

 /** bool find(const int k, Item& x) note that is this we call it with find(2,a) where a=1,2,.. i.e we dont need to pass it by reference
 by us because the function automatically gathers its reference 
 */
namespace cs202 {

template<class Item> class LinearList{
	private:
		int MaxSize;
		Item *element;    // 1D dynamic array
        int len;
	
	public:
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		LinearList();                                                 //this is called constructor declaration

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList(const int& MaxListSize);

		// Constuctor with size and default value as input
        LinearList(const int& isize, const Item& val);    

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~LinearList();

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
	    Item& operator[](const int& i); //return i'th element of list
		
		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty();

		/* Returns the actual length (number of elements) in the list.
     		 * */
		int  length();

		/* Returns the maximum size of the list.
     		 * */
		int  maxSize();

 		// Appending an element to the LinearList
        // The asymptotic time complexity of this function
        // should be O(1)
        void push_back(const Item& x);
		
		/* Returns the k-th element of the list. 
		 * */
		Item  returnListElement(const int k);

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */

		// Find the index of first occurence of an item in the list
        // Return size of list if item not found
        // 0-based indexing
        int find(const Item& x);

		// Fills all the elements with a default value
        void fill(const Item& item);

		bool insert_at_k(const int k, Item& x);

		// Returns the capacity of the LinearList
        unsigned int capacity();   

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		int  search(Item& x);

		// Remove all occurences of an item in the list
        void erase(const Item& x);

        // Remove the item in the list at position pos
        void erase_pos(const int& pos);

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteElement(const int  k, Item& x);

		/* Insert x after k-th element.
		 * */
		void  insert(const int  k, Item& x);


		//we can also define this itertor class by defining just simply class iterator{};
		//and then externally use LinearList::iterator:: here define the function definitions
		/*class iterator{                             
          private:
            T* elem_;
          public:
            iterator()        : elem_(nullptr);   //contructor definitions 
            iterator(T* ptr)  : elem_(ptr);
            ~iterator();
            T& operator*();					return {    };
            void operator=(T *ptr)  		return { elem_ = ptr  };
            void operator=(iterator iter)  	return {   };
            void operator++()				return { elem_++  };
            void operator--()				return { elem_--  };
            bool operator!=(T* ptr)			return {   };
            bool operator==(T* ptr)			return {   };
            bool operator!=(iterator iter)	return {   };
            bool operator==(iterator iter)	return {   };
            iterator operator+(int i)		return {   };
            iterator operator-(int i)		return {   };
        };

        iterator begin();
        iterator end();*/


};

template<class Item>
LinearList<Item> :: LinearList(): element(new Item[0]), len(0){

}

// Constuctor with size and default value as input
template <class Item>
LinearList<Item> :: LinearList(const int& isize, const Item& val){
	element = new Item[isize];
	len = isize;
	for(int i=0;i<len;i++){
		element[i]=val;
	}
	MaxSize = isize;
}    


template<class Item>
LinearList<Item> :: LinearList(const int& MaxListSize){
    element = new Item[MaxListSize];
	for(int i=0;i<MaxListSize;i++){
		element[i]=0;
	}
	len = MaxListSize;
}

template <class Item>
LinearList<Item> :: ~LinearList(){
    free(element);
}

template<class Item>
bool LinearList<Item> :: isEmpty(){
     return len==0;
}

template<class Item>
int LinearList<Item> :: length(){
     return len;
}

template<class Item>
int LinearList<Item> :: maxSize(){
     return MaxSize;
}

template <class Item>
Item LinearList<Item> :: returnListElement(const int k){
	return element[k-1];
}

template <class Item>
Item& LinearList<Item> :: operator[](const int& i){
	return element[i];
}

template <class Item>
bool LinearList<Item> :: insert_at_k(const int k, Item& x){
	if(k>=1 && k<=len){
	   element[k-1]=x;	
	   return true;
	}
}
template <class Item>
unsigned int LinearList<Item> :: capacity(){
	return MaxSize;
}   

template <class Item>
void LinearList<Item> :: push_back(const Item& x){
	Item* new_list = new Item[len+1];
	for(int i=0;i<len;i++){
		new_list[i] = element[i];
	}
	new_list[len]=x;
	free(element);
	element = new_list;
	len++;
}

template <class Item>
void LinearList<Item> :: fill(const Item& x){
	for(int i=0;i<len;i++){
		element[i]=x;
	}
}

template <class Item>
int LinearList<Item> :: find(const Item& x){
	for(int i=0;i<len;i++){
		if(element[i]==x){
			return i;
		}
	}
	return len;
}



template <class Item>
int LinearList<Item> :: search(Item& x){
    for(int i=0;i<len;i++){
		if(element[i]==x){
			return i;
		}
	}
	return 0;
}

template <class Item>
void LinearList<Item> :: erase(const Item& x){
	int count = 0;
	int j=0;
	for(int i=0;i<len;i++){
		if(element[i]==x){
			count++;
			element[i]=0;
		}
	}

	Item *new_list = new Item[len-count];
	for(int i=0;i<len;i++){
		if(element[i]!=0){
			new_list[j]=element[i];
			j++;
		}
	}
	free(element);
	element = new_list;
	len = len-count;
}


template <class Item>
void LinearList<Item> :: erase_pos(const int& pos){
	element[pos-1] = 0;
	int j=0;
	Item *new_list = new Item[len-1];
	for(int i=0;i<len;i++){
		if(element[i]!=0){
			new_list[j]=element[i];
			j++;
		}
	}
	element = new_list;	
	len = len -1;
}


template <class Item>
void LinearList<Item> :: deleteElement(const int  k, Item& x){
	if(k<=len && k>=1){
        element[k-1]=x;
	}
	len--;
}

template <class Item>
void LinearList<Item> :: insert(const int  k, Item& x){
    int i;
	Item* temp = new Item[len-k];
	for(int i=k;i<len;i++){
		temp[i-k]= element[i];
	}
	element[k]=x;
	for(int j=k+1;j<len+1;j++){
		element[j]=temp[j-(k+1)];
	}
	len++;
}

//end of namespace
}

#endif