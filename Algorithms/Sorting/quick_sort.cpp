#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int>&,int,int);
int partition(vector<int>&,int,int);
void swap(int*,int*);
int main(){

	vector<int> arr = {6,3,2,1,5,7,9};

	quick_sort(arr,0,arr.size()-1);

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}

int partition(vector<int>&a,int low,int high){

	int pivot = a[high];
	int i = low-1;

	for(int j=low;j<high;j++){

		if(a[j]<=pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}

	swap(&a[i+1],&a[high]);

	return (i+1);
}

void quick_sort(vector<int>&a,int l,int r){
	if(l<r){
		int pi = partition(a,l,r);
		quick_sort(a,l,pi-1);
		quick_sort(a,pi+1,r);
	}
}

void swap(int *a ,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	//free(temp);
}