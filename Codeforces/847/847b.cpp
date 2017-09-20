#include <iostream>
#include <vector>

using namespace std;

bool allvisited(int* mark,int n){
	for(int i=0 ; i<n ; i++){
		if(mark[i] == -1){
			return false;
		}
	}

	return true;
}

int main(){
	
	int n;
	cin>>n;

	vector<int> arr(n,0);
	int mark[n];

	for(int i=0 ; i<n ; i++){
		mark[i] = -1;
	}

	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}

	int count = 0;

	while(count<n){

		int first = -1;
		int prev = -1;

		for(int i=0 ; i<n ; i++){
			if(mark[i] == -1){
				first = i;
				cout<<arr[i]<<" ";
				mark[i] = 0;
				count++;
				prev = i;
				break;
			}
		}
		
		for(int i=first+1 ; i<n ; i++){

			if( mark[i] == -1 and arr[i] > arr[prev]){
				cout<<arr[i]<<" ";
				prev = i;
				count++;
				mark[i] = 0;
			}
		}

		cout<<endl;
	}


	return 0;
}