#include <iostream>
#include <vector>

using namespace std;

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

			case 0 : 

				swap(&arr[low++],&arr[mid++]);
				break;
			case 1 :
				mid++;
				break;
			case 2:
				swap(&arr[mid],&arr[high--]);
		}
	}

}


int main(){
	
	vector<int> arr = { 0 , 2 , 0 , 1 , 1 , 2 , 0 , 1 , 2 , 0};

	sortit(arr);

	for(int i=0 ; i<arr.size() ; i++){
		cout<<arr[i]<<" ";
	}

	cout<<endl;

	return 0;
}