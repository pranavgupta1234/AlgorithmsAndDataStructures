#include <iostream>
#include <vector>

using namespace std;

//this is a general 3 way partitioning problem 
//it is in place and requires constant extra space


void swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortit(vector<int>& arr){

	int low = 0;
	int mid = 0;
	int high = arr.size() - 1;

	while(mid <= high){

		switch(arr[mid]){

			case 7 : 

				swap(&arr[low++],&arr[mid++]);
				break;
			case 14 :
				mid++;
				break;
			case 54:
				swap(&arr[mid],&arr[high--]);
				break;
		}
	}

}


int main(){
	
	vector<int> arr = { 7 , 14 , 54 , 54 , 14 , 54 , 7 , 7 , 54 , 14};

	sortit(arr);

	for(int i=0 ; i<arr.size() ; i++){
		cout<<arr[i]<<" ";
	}

	cout<<endl;

	return 0;
}