#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <string.h>
using namespace std;

/* Templates are the foundation of generic programming, which involves writing code in a
 way that is independent of any particular type.
*/
template <class Item>
class Sort{
 	private:


    public:

    	void InsertionSort(LinearList<Item>& A,int low,int high);

    	void RankSort(LinearList<Item>& A,int low,int high);

    	void BubbleSort(LinearList<Item>& A,int low,int high);

    	void SelectionSort(LinearList<Item>& A,int low,int high);

    	void Swap(int* a,int *b);

};

template <class Item>
void Sort<Item> :: InsertionSort(LinearList<Item>& A,int low,int high){
	int key,i;
	for(int j=low+1;j<high;j++){
		key = A[j];
		i=j-1;
		while(i>low-1&&A[i]>key){
			A[i+1]= A[i];
			i=i-1;
		}
		A[i+1]=key;
	}
} 
template <class Item>
void Sort<Item> :: RankSort(LinearList<Item>& A,int low,int high){
	Item* rank = new Item[A.length()-low+1];
	Item* tempList = new Item[A.length()-low+1];

	for(int i=low ;i<=high;i++){
		rank[i-low] =1;
	}
	for(int i=low+1;i<=high;i++){
		for(int j=low;j<i;j++){
			if(A[j]<=A[i]){
				rank[i-low]++;
			}
			else{
				rank[j-low]++;
			}
		}
	}

	for(int i=low;i<=high;i++){
		tempList[rank[i-low]-1]=A[i];
	}
	for(int i=low;i<=high;i++){
		A[i]=tempList[i-low];
	}
	
} 

template <class Item>
void Sort<Item> :: BubbleSort(LinearList<Item>& A,int low,int high){
    for (int i = low; i < high-1; i++)      
        for (int j = 0; j < high-i-1; j++) 
            if (A[j] > A[j+1])
            	Swap(&A[j], &A[j+1]);
	
} 

template <class Item>
void Sort<Item> :: SelectionSort(LinearList<Item>& A,int low,int high){

	int min_idx;
 
    for (int i = low; i < high-1; i++)
    {
        min_idx = i;
        for (int j = i+1; j < high; j++)
          if (A[j] < A[min_idx])
            min_idx = j;

        Swap(&A[min_idx], &A[i]);
    }
} 
template <class Item>
void Sort<Item> :: Swap(int *a,int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

#endif