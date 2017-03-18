#ifndef STACK_HPP_
#define STACK_HPP_
#include "list.hpp"

namespace stk{

template<typename T>
class stack{

private:

    ll::list<T> list_for_stack;

public:
    /*
    * Constructs a new stack.
    */
    stack();
    /*
    * Pushes t to on the top of the stack.
    */
    void push(const T& t);
    /*
    * Returns the element at the top of the stack.
    * Also removes the top element from the stack.
    */
    T pop();
    /*
    * Returns the element at the top of the stack.
    * Does not remove the top element.
    */
    T top();
    /*
    * Returns the number of elements currently in the stack.
    */
    int size();
    /*
    * Returns a boolean indicating whether the stack is empty or not.
    */
    inline bool empty();
    /*
    * Destructor
    * Fress the memory occupied by the stack elements.
    */
    ~stack();

    void print_stack();
};

template<class T>
stack<T> :: stack(){
    
}

template<class T>
stack<T> :: ~stack(){
    
}

template<class T>
void stack<T> :: push(const T& t){
    list_for_stack.insert(t);
}

template<class T>
T stack<T> :: pop(){
    if(list_for_stack.length()!=0){
        T element = list_for_stack.top_element();
        list_for_stack.remove_first();
        return element;
    }
}

template<class T>
T stack<T> :: top(){
    if(list_for_stack.length()!=0){
        return list_for_stack.top_element();
    }
}

template<class T>
int stack<T> :: size(){
    return list_for_stack.length();
}

template<class T>
bool stack<T> :: empty(){
    return ( list_for_stack.length()!=0 ? false : true );
}

template<class T>
void stack<T> :: print_stack(){
    list_for_stack.printList();
}



//end of namespace
}

#endif