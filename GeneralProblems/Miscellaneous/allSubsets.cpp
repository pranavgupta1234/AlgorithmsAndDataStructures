#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
	
	int n;
	cin>>n;
	int arr[n];
	memset(arr,0,n*sizeof(arr[0]));
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}

	for(int i=0 ; i<pow(2,n) ; i++){
		for(int j=0 ; j<n ; j++){
			int sum = 0;
			if(i&(1<<j)){
				cout<<arr[j]<<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}