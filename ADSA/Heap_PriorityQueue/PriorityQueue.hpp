// Purpose: Learn Heaps And PriorityQueue
// Author: Pranav Gupta
// Date of Creation: 
// Bugs:

#ifndef MIN_PRIORITY_QUEUE
#define MIN_PRIORITY_QUEUE 1
#include "seqLinearList.hpp"
#include <limits.h>

namespace cs202{
	
template<typename T>
class MinPriorityQueue{
	// Private attributes and functions for class
	// If you need any more functions / attributes
	// define them yourself along with proper reasoning
	// why they were introduced.
	// DO NOT DELETE ANY OF THE MEMBERS FROM BELOW
	// YOU NEED TO USE THEM ALL.

private: 
	// Primary container used in MinPriorityQueue
	LinearList<T> heap;
	int heap_size;

	// heapifies the heap at position pos 
	void heapify(const size_t& pos);

	// return the parent of an element
	inline int parent(const size_t& pos);

	// return the left child of an element
	inline int left_child(const size_t& pos);

	// return the right child of an element
	inline int right_child(const size_t& pos);

	void swap(T* a,T* b){
		T c = *b;
		*b = *a;
		*a = c;
	}

public:
	// default constructor
	MinPriorityQueue();

	// construct a heap from the elements of a seqLinearList
	MinPriorityQueue(const LinearList<T>& v);

	//copy constructor
	MinPriorityQueue(MinPriorityQueue<T>& q);

	// insert a value to the heap
	void insert(const T& a);

	// get the minimum element from the heap
	inline T& minimum();

	// return the minimum element from the heap and remove it
	// as well
	T extract_min();

	// return the heap size
	inline int size_heap();

	// build a heap from elements of a seqLinearList container 
	void build_heap(const LinearList<T>& v);

	// check if MinPriorityQueue is empty
	inline bool empty();

	// heap_decrease_key function
	void heap_decrease_key(const size_t& pos);

	//deletes a key
	void deleteKey(const size_t& pos);

	void printHeap();
	
};

template<typename T>
void MinPriorityQueue<T> :: heapify(const size_t& pos){

	int left = left_child(pos);
	int right = right_child(pos);
	int small = pos;   									//initially consider the parent as smallest

	if(left < heap_size and heap[left] < heap[pos]){
		small = left;									//first check with left child for small element
	}
	if(right < heap_size and heap[right] < heap[small]){
		small = right;									//now check with right child and small must have been modified if left one was small from parent
	}
	if(small != pos){
		swap(&heap[pos],&heap[small]);
		heapify(small);
	}

}

template<typename T>
int MinPriorityQueue<T> :: parent(const size_t& pos){
	return (pos/2);
}

template<typename T>
int MinPriorityQueue<T> :: left_child(const size_t& pos){
	return (2*pos + 1);
}

template<typename T>
int MinPriorityQueue<T> :: right_child(const size_t& pos){
	return (2*pos + 2);
}

template<typename T>
MinPriorityQueue<T> :: MinPriorityQueue(){

	//heap.resize(11);
	heap_size = 0;
}

template<typename T>
MinPriorityQueue<T> :: MinPriorityQueue(const LinearList<T>& v){
	build_heap(v);
}

template<typename T>
MinPriorityQueue<T> :: MinPriorityQueue(MinPriorityQueue<T>& q){
	
	heap_size = q.size_heap();
		
	for(int i = 0; i < heap_size; i++)
		heap.push_back(q.heap[i]);
}


template<typename T>
void MinPriorityQueue<T> :: insert(const T& a){
	
	heap_size++;
	heap.push_back(a);
	int i = heap_size - 1;

	while(i!=0 and heap[parent(i)] > heap[i]){
		swap(&heap[parent(i)],&heap[i]);
		i = parent(i);
	}
}	

template<typename T>
T& MinPriorityQueue<T> :: minimum(){
	if(heap_size>0){
		return heap[0];
	}
}

template<typename T>
T MinPriorityQueue<T> :: extract_min(){
	
	if(heap_size == 1){
		heap_size--;
		return heap[0];
	}

	T root = heap[0];
	heap[0] = heap[heap_size-1];
	heap_size--;
	heapify(0);

	return root;
}

template<typename T>
void MinPriorityQueue<T> :: deleteKey(const size_t& pos){
	heap_decrease_key(pos);
	extract_min();
}

template<typename T>
int MinPriorityQueue<T> :: size_heap(){
	return heap_size;
}

template<typename T>
void MinPriorityQueue<T> :: build_heap(const LinearList<T>& v){

	for(int i=0;i<v.size();i++){
		insert(v[i]);
	}

}

template<typename T>
bool MinPriorityQueue<T> :: empty(){
	if(heap_size==0){
		return true;
	}else{
		return false;
	}
}

template<typename T>
void MinPriorityQueue<T> :: heap_decrease_key(const size_t& pos){

	heap[pos] = INT_MIN;
	int i = pos;

	while(i!=0 and heap[parent(pos)] > heap[i]){
		swap(&heap[parent(i)],&heap[i]);
		i = parent(i);
	}
	
}

template<typename T>
void MinPriorityQueue<T> :: printHeap(){
	for(int i=0;i<heap_size;i++){
		std::cout<<heap[i]<<" ";
	}
	std::cout<<std::endl;
}

//end of namespace
}
	
#endif 