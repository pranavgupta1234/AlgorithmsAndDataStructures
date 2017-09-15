#include <iostream>
#include <vector>

using namespace std;

int first(vector<int>& arr,int key,int low,int high){

	if(low<=high){

		int mid = (low + high) / 2;

		if(mid == 0 or arr[mid] == key and arr[mid-1] < key){
			return mid;
		}else if(arr[mid] > key){
			return first(arr,key,0,mid-1);
		}else {
			return first(arr,key,mid+1,high);
		}

	}else{
		return -1;
	}

}

int last(vector<int>& arr,int key,int low,int high){

	if(low<=high){

		int mid = (low + high) / 2;

		if(mid == arr.size() -1 or arr[mid] == key and arr[mid+1] > key){
			return mid;
		}else if(arr[mid] > key){
			return first(arr,key,0,mid-1);
		}else {
			return first(arr,key,mid+1,high);
		}

	}else{
		return -1;
	}

}

int occurences(vector<int>& arr,int key){

	int i,j;

	i = first(arr,key,0,arr.size()-1);

	if(i==-1){
		return -1;
	}

	j = last(arr,key,i,arr.size()-1);

	return j-i+1;

}

int main(){
	
	vector<int> arr = { 1 ,2 , 3 ,3 , 3, 5 ,6 ,7};

	cout<<occurences(arr,3)<<endl;

	return 0;
}