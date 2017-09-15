#include <iostream>
#include <vector>

using namespace std;


bool binarySearch(vector<int>& arr,int low,int high,int key){

	if(low<=high){

		int mid = (low + high)/2;

		if(arr[mid] == key){
			return true;
		}else if(arr[mid] > key){
			return binarySearch(arr,low,mid-1,key);
		}else{
			return binarySearch(arr,mid+1,high,key);
		}

	}else{

		return false;

	}

}


int findPivot(vector<int>& arr,int low,int high){

	if(high<low){
		return -1;
	}
	if(high == low){
		return low;
	}

	int mid = (high + low)/2;

	if(mid < high and arr[mid] > arr[mid+1]){
		return mid;
	}else if(mid > low and arr[mid] < arr[mid-1]){
		return mid-1;
	}else if(arr[low]>=arr[mid]){
		return findPivot(arr,low,mid-1);
	}

	return findPivot(arr,mid+1,high);

}

bool pivotedBinarySearch(vector<int>& arr,int key){

	int size = arr.size();

	int pivot = findPivot(arr,0,size-1);

	if(pivot == -1){
		return binarySearch(arr,0,size-1,key);
	}

	if(arr[pivot] == key){
		return true;
	}else if(arr[pivot] > key){
		return binarySearch(arr,pivot+1,size-1,key);
	}else{
		return binarySearch(arr,0,pivot-1,key);
	}

}


int main(){
	
	vector<int> arr = { 3 , 4 , 5, 1, 2};

	cout<<(pivotedBinarySearch(arr,6) ? "Found" : "Not Found");

	cout<<endl;

	return 0;
}