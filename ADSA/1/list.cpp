#include "seqLinearList.h"
#include "Sort.h"
#include <ctime>

void display(LinearList<int>&);

int main() { 
    int maxSize;
    int length;
    int element;
    int sortType;
    int start;
    int stop;

    Sort<int> sort;

    cout<<"Enter the maxsize of the list :: "<<endl;
    cin>>maxSize;
    cout<<"Enter the size of the list"<<endl;
    cin>>length;
    LinearList<int> myList(maxSize,length);
    cout<<"Enter the number of elements in the list"<<endl;
    for(int i=0;i<length;i++){
        cout<<"Enter the "<<i+1<<" element : ";
        cin>>element;
        myList.find(i+1,element);
    }
    
    cout<<"Entered List is :: ";
    for(int i=0;i<length;i++){
        cout<<myList[i]<<" ";
    }
    cout<<endl;

    cout<<"Select the sorting algorithm (Choose 1,2,3,4):: "<<endl;
    cout<<"1. Insertion Sort"<<endl;
    cout<<"2. Rank Sort"<<endl;
    cout<<"3. Bubble Sort"<<endl;
    cout<<"4. Selection Sort"<<endl;
    cin>>sortType;
    switch(sortType){
        case 1:
            start = clock();
            sort.InsertionSort(myList,0,length);
            display(myList);
            stop = clock();
            cout << "Execution Time : " << (stop-start)/double(CLOCKS_PER_SEC)*1000 <<" s"<<endl;
            break;
        case 2:
            start = clock();
            sort.RankSort(myList,0,length-1);
            display(myList);
            stop = clock();
            cout << "Execution Time : " << (stop-start)/double(CLOCKS_PER_SEC)*1000 <<" s"<<endl;
            break;
        case 3:
            start = clock();
            sort.BubbleSort(myList,0,length);
            display(myList);
            stop = clock();
            cout << "Execution Time : " << (stop-start)/double(CLOCKS_PER_SEC)*1000<<" s"<<endl;
            break;
        case 4:
            start = clock();
            sort.SelectionSort(myList,0,length);
            stop = clock();
            cout << "Execution Time : " << (stop-start)/double(CLOCKS_PER_SEC)*1000 <<" s"<<endl;
            display(myList);
            break;     
    }
} 

void display(LinearList<int>& A){
    for(int i=0;i<A.length();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}