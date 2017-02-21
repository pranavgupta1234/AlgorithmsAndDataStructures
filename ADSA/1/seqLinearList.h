#ifndef SEQLINEARLIST_H
#define SEQLINEARLIST_H
#include <iostream>
#include <string.h>
using namespace std;

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

		LinearList(const int& MaxListSize,const int& length);

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

		/* Returns the k-th element of the list. 
		 * */
		Item  returnListElement(const int k);

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x);

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		int  search(Item& x);

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteElement(const int  k, Item& x);

		/* Insert x after k-th element.
		 * */
		void  insert(const int  k, Item& x);
};

template<class Item>
LinearList<Item> :: LinearList(): MaxSize(10), element(new Item[0]), len(0){

}

template<class Item>
LinearList<Item> :: LinearList(const int& MaxListSize){
    element = new Item[MaxListSize];
	for(int i=0;i<MaxListSize;i++){
		element[i]=0;
	}
	len = MaxListSize;
}

template<class Item>
LinearList<Item> :: LinearList(const int& MaxListSize,const int& length){
    element = new Item[MaxListSize];
	for(int i=0;i<MaxListSize;i++){
		element[i]=0;
	}
	len = length;
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
bool LinearList<Item> :: find(const int k, Item& x){
	if(k>=1 && k<=len){
	   element[k-1]=x;	
	   return true;
	}else{
	   cout<<"This position does not exist"<<endl;
       return false;
	}
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
void LinearList<Item> :: deleteElement(const int  k, Item& x){
	if(k<=len && k>=1){
        element[k-1]=x;
	}
	else{
		cout<<"Sorry element can't be accessed";
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

#endif