// Driver Program for testing `sorting` class
// Author: Pranav Gupta
// Roll Number: B15227
#include "seqLinearList.h"
#include "sorting.h"
#include "timer.h"
#include <fstream>

using namespace cs202;

void display(LinearList<int>&);

int main(int argc,char *argv[]) { 
    
    std::ofstream myfile;
    myfile.open ("result.dat",std::ios_base::app);

    //class declarations
    Sort<int> sort;
    timer time_estimator;
    
    int size;
    int val;
    int element;
    int sortType;

    if(argc==4){

        //creating the required list with required size
        LinearList<int> myList(atoi(argv[1]),0);
        sortType =atoi(argv[2]);

        for(int i=0;i<myList.length();i++){
            std::cout<<"Enter the "<<i+1<<" element : ";
            std::cin>>element;
            myList.insert_at_k(i+1,element);
        }

    std::cout<<"Sorting your messed stuff ;p ..."<<std::endl;
    
    switch(sortType){
        case 1:
            time_estimator.start();
            sort.InsertionSort(myList,0,myList.length());
            display(myList);
            time_estimator.stop();
            std::cout<<"Congratulations ! Your Task is DONE !"<<std::endl;
            time_estimator.print();
            myfile <<size<<" "<<time_estimator.last_timing()<<std::endl;
            myfile.close();
            break;
        case 2:
            time_estimator.start();
            sort.RankSort(myList,0,myList.length()-1);
            display(myList);
            time_estimator.stop();
            std::cout<<"Congratulations ! Your Task is DONE !"<<std::endl;
            time_estimator.print();
            myfile <<size<<" "<<time_estimator.last_timing()<<std::endl;
            myfile.close();
            break;
        case 3:
            time_estimator.start();
            sort.BubbleSort(myList,0,myList.length());
            display(myList);
            time_estimator.stop();
            std::cout<<"Congratulations ! Your Task is DONE !"<<std::endl;
            time_estimator.print();
            myfile <<size<<" "<<time_estimator.last_timing()<<std::endl;
            myfile.close();
            break;
        case 4:
            time_estimator.start();
            sort.SelectionSort(myList,0,myList.length());
            time_estimator.stop();
            std::cout<<"Congratulations ! Your Task is DONE !"<<std::endl;
            time_estimator.print();
            myfile <<size<<" "<<time_estimator.last_timing()<<std::endl;
            myfile.close();
            display(myList);
            break;     
        case 5:
            time_estimator.start();
            sort.MergeSort(myList,0,myList.length()-1);
            time_estimator.stop();
            std::cout<<"Congratulations ! Your Task is DONE !"<<std::endl;
            time_estimator.print();
            myfile <<size<<" "<<time_estimator.last_timing()<<std::endl;
            myfile.close();
            display(myList);
            break;
        case 6:
            time_estimator.start();
            sort.MergeSort(myList,0,myList.length()-1);
            time_estimator.stop();
            std::cout<<"Congratulations ! Your Task is DONE !"<<std::endl;
            time_estimator.print();
            myfile <<size<<" "<<time_estimator.last_timing()<<std::endl;
            myfile.close();
            display(myList);
            break;
        }

        exit(0);

    }

    if(argc<3){

        std::cout<<"Missing arguments for input , please follow the below guide for your input :) "<<std::endl;
        std::cout<<"A. First argument is your executable file name eg ./filename"<<std::endl;
        std::cout<<"B. Second argument is the number of elements you want to sort eg. 100001"<<std::endl;
        std::cout<<"C. Third argument is the algorithm you want to use for sorting your numbers , guide is given below ::"<<std::endl;
        std::cout<<"Select the sorting algorithm (Choose 1,2,3,4,5,6 according to mapped values shown below ):: "<<std::endl;
        std::cout<<"1. Insertion Sort"<<std::endl;
        std::cout<<"2. Rank Sort"<<std::endl;
        std::cout<<"3. Bubble Sort"<<std::endl;
        std::cout<<"4. Selection Sort"<<std::endl;
        std::cout<<"5. Merge Sort"<<std::endl;
        std::cout<<"6. Quick Sort"<<std::endl;
        std::cout<<"D. Fourth argument is the path to your input file eg /input/asc_5000.in"<<std::endl;
        std::cout<<"E. Finally your input in command line may look something like this ./list 500001 3 /input/num.txt"<<std::endl<<std::endl;

        std::cout<<"If you want to give custom input write ./filename size_of_input(int) sort_type 1"<<std::endl;        
        std::cout<<"Aborting..."<<std::endl;

        exit(0);
    }



    //input values from command line
    size = atoi(argv[1]);
    sortType = atoi(argv[2]);
    val = 0;

    //creating the required list with required size
    LinearList<int> myList(size,0);
    
    for(int i=0;i<myList.length();i++){
        //std::cout<<"Enter the "<<i+1<<" element : ";
        std::cin>>element;
        myList.insert_at_k(i+1,element);
    }
    
    std::cout<<"Sorting your messed stuff ;p ..."<<std::endl;
    
    switch(sortType){
        case 1:
            time_estimator.start();
            sort.InsertionSort(myList,0,myList.length());
            //display(myList);
            time_estimator.stop();
            std::cout<<"Congratulations ! Your Task is DONE !"<<std::endl;
            time_estimator.print();
            myfile <<size<<" "<<time_estimator.last_timing()<<std::endl;
            myfile.close();
            break;
        case 2:
            time_estimator.start();
            sort.RankSort(myList,0,myList.length()-1);
            //display(myList);
            time_estimator.stop();
            std::cout<<"Congratulations ! Your Task is DONE !"<<std::endl;
            time_estimator.print();
            myfile <<size<<" "<<time_estimator.last_timing()<<std::endl;
            myfile.close();
            break;
        case 3:
            time_estimator.start();
            sort.BubbleSort(myList,0,myList.length());
            //display(myList);
            time_estimator.stop();
            std::cout<<"Congratulations ! Your Task is DONE !"<<std::endl;
            time_estimator.print();
            myfile <<size<<" "<<time_estimator.last_timing()<<std::endl;
            myfile.close();
            break;
        case 4:
            time_estimator.start();
            sort.SelectionSort(myList,0,myList.length());
            time_estimator.stop();
            std::cout<<"Congratulations ! Your Task is DONE !"<<std::endl;
            time_estimator.print();
            myfile <<size<<" "<<time_estimator.last_timing()<<std::endl;
            myfile.close();
            //display(myList);
            break;     
        case 5:
            time_estimator.start();
            sort.MergeSort(myList,0,myList.length()-1);
            time_estimator.stop();
            std::cout<<"Congratulations ! Your Task is DONE !"<<std::endl;
            time_estimator.print();
            myfile <<size<<" "<<time_estimator.last_timing()<<std::endl;
            myfile.close();
            //display(myList);
            break;
        case 6:
            time_estimator.start();
            sort.MergeSort(myList,0,myList.length()-1);
            time_estimator.stop();
            std::cout<<"Congratulations ! Your Task is DONE !"<<std::endl;
            time_estimator.print();
            myfile <<size<<" "<<time_estimator.last_timing()<<std::endl;
            myfile.close();
            //display(myList);
            break;
    }
} 

void display(LinearList<int>& A){
    std::cout<<"Sorted Array is ::"<<std::endl;
    for(int i=0;i<A.length();i++){
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
}