#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <string.h>

/* Templates are the foundation of generic programming, which involves writing code in a
 way that is independent of any particular type.
*/

namespace cs202{

template <class Item>
class Sort{

 	private:


    public:

    	void InsertionSort(LinearList<Item>& A,int low,int high);

    	void RankSort(LinearList<Item>& A,int low,int high);

    	void BubbleSort(LinearList<Item>& A,int low,int high);

    	void SelectionSort(LinearList<Item>& A,int low,int high);

    	void MergeSort(LinearList<Item>& A,int low,int high);

    	void QuickSort(LinearList<Item>& A,int low,int high);

    	void merger(LinearList<Item>&A,int l,int m,int r);

		int partition(LinearList<Item>& arr, int low, int high);

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
void Sort<Item> :: MergeSort(LinearList<Item>& A,int low,int high){
	if(high>low){
		int m= low + (high-low)/2;
		MergeSort(A,low,m);
		MergeSort(A,m+1,high);
		merger(A,low,m,high);
	}
}

template <class Item>
void Sort<Item> :: merger(LinearList<Item>&a,int l,int m,int r){

	//calculating length of individual halfs which are needed to be merged
	int first_half_length = m-l+1;
	int second_half_length = r-m;

	//creating temporary storage for these arrays
	int first_half[first_half_length];
	int second_half[second_half_length];

	//filling up the temporary arraay with values
	for(int i=0;i<first_half_length;i++){
		first_half[i]=a[l+i];    // note that the mth element is include in first array i.e arr[m]
	}
	for(int i=0;i<second_half_length;i++){
		second_half[i]=a[m+1+i];
	}
 	int i=0,j=0,k=l;   				// i for first array and j for second array and k for final array remember that initial value for k will be l

	while(i<first_half_length&&j<second_half_length){
		if(first_half[i]<=second_half[j]){
			a[k]=first_half[i];
			i++;
		}
		else{
			a[k]=second_half[j];
			j++;
		}
		k++;
	}

	//copy if there are some remaining elements
	while(i<first_half_length){
		a[k]=first_half[i];
		i++;
		k++;
	}
	while(j<second_half_length){
		a[k]=second_half[j];
		j++;
		k++;
	}
}
template <class Item>
int Sort<Item> :: partition(LinearList<Item>& arr, int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
template <class Item>  
void Sort<Item> :: QuickSort(LinearList<Item>& arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template <class Item>
void Sort<Item> :: Swap(int *a,int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

}

#endif