#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void display(vector<int>&);
void swap(int*,int*);
void InsertionSort(vector<int>&);
void SelectionSort(vector<int>&);
int main(){
	int element;
	vector<int> array;
	for(int i=0;i<10;i++){
		cin>>element;
		array.push_back(element);		
	}
	display(array);

	SelectionSort(array);

	display(array);

}

void display(vector<int>& array){

	for(int i=0;i<array.size();i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

void InsertionSort(vector<int>& arr){
	int key;
	int j;
	for(int i=1;i<arr.size();i++){

		key = arr[i];
		j=i-1;

		while(j>=0&&arr[j]>key){

			arr[j+1]=arr[j];
			j--;
		}

		arr[j+1]=key;
	}
}

void SelectionSort(vector<int>& arr){

	for(int i=0;i<arr.size()-1;i++){

		int min_index=i;

		for(int j=i+1;j<arr.size();j++){
			if(arr[j]<arr[min_index]){
				min_index = j;
			}
		}

		swap(&arr[i],&arr[min_index]);
	}
}

void BubbleSort(vector<int>& arr){
	
}

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}