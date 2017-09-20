#include <iostream>
#include <algorithm>
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
	vector<int> sorted;
	int mark1[n];
	int marks[n];
	for(int i=0 ; i<n ; i++){
		marks[i] = -1;
		mark1[i] = -1;
	}

	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}	

	sorted = arr;

	sort(sorted.begin(),sorted.end());


	while(!allvisited(mark1,n)){
		//cout<<"hii"<<endl;
		int i=0;
		int j=0;

		while(i<n and j<n){

			while(mark1[i] != -1){
				i++;
			}

			if(arr[i] == sorted[j] and mark1[i] !=0){
				cout<<arr[i]<<" ";
				i++;
				j++;
				mark1[i] = 0;
			}else if(arr[i] > sorted[j]){
				j++;
			}else{
				i++;
			}
		}
		cout<<endl;
	}


	return 0;
}