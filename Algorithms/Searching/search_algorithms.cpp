#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>&,int,int,int);
void InsertionSort(vector<int>&);

int main(){
	int temp;
	vector<int> arr ;
	for(int i=0;i<10;i++){
		cin>>temp;
 		arr.push_back(temp);
	}
	cout<<"Enter the element you want to search : ";
	cin>>temp;
	InsertionSort(arr);

	//cout<<binary_search(arr,0,arr.size(),temp);
	cout<<(binary_search(arr,0,arr.size(),temp)!= -1 ? binary_search(arr,0,arr.size(),temp) : -1);

}

/* r -> lower index , l -> higher index and x -> element to be searched
*/
int binary_search(vector<int>& arr,int r,int l,int x){
	
	if(l>=r){

		int mid = r + (l-r)/2;

		if(arr[mid]== x)
 			return arr[mid];
 		else if( arr[mid] > x)
 			return binary_search(arr,r,mid-1,x);
 		else
 			return binary_search(arr,mid+1,l,x);
	}
	else{
		return -1;
	}
}

void InsertionSort(vector<int>& arr){
	int key,j;

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