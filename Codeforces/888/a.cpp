#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int extremums = 0;
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}

	for(int i=1 ; i<n-1 ; i++){
		if(arr[i] > arr[i-1] and arr[i] > arr[i+1]){
			extremums++;
		}
		if(arr[i] < arr[i-1] and arr[i] < arr[i+1]){
			extremums++;
		}
	}
	cout<<extremums<<endl;
	return  0;
}