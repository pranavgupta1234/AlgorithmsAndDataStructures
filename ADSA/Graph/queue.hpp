#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "list.hpp"

namespace q
{
template <class T>
class queue{

private:

    ll::list<T> list_for_queue;

public:
    /*
    * Constructs a new queue.
    */
    queue();
    /*
    * Pushes t to at the back of the queue.
    */
    void push(const T& t);
    /*
    * Returns the element at the front of the queue.
    * Also removes the front element from the queue.
    */
    T pop();
    /*
    * Returns the element at the front of the queue.
    * Does not remove the front element.
    */
    T front();
    /*
    * Returns the number of elements currently in the queue.
    */
    inline int size();
    /*
    * Returns a boolean indicating whether the queue is empty or not.
    */
    inline bool empty();
    /*
    * Destructor
    * Fress the memory occupied by the queue elements.
    */
    ~queue();

    void print_queue();
};

template<class T>
queue<T> :: queue(){
    
}

template<class T>
queue<T> :: ~queue(){
    
}

template<class T>
void queue<T> :: push(const T& t){
    list_for_queue.append(t);
}

template<class T>
T queue<T> :: pop(){
    if(list_for_queue.length()!=0){
        T element = list_for_queue.top_element();
        list_for_queue.remove_first();
        return element;
    }
}
template<class T>
T queue<T> :: front(){
    if(list_for_queue.length()!=0){
        return list_for_queue.top_element();
    }
}

template<class T>
int queue<T> :: size(){
    return list_for_queue.length();
}

template<class T>
bool queue<T> :: empty(){
    return (list_for_queue.length()!=0 ? false : true);
}

template<class T>
void queue<T> :: print_queue(){
    if(list_for_queue.length()!=0){
        list_for_queue.printList();
    }
}

//end of namespace
}
#endif