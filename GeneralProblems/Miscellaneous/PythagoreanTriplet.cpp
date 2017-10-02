#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isTripletPresent(vector<int>& arr){
	for(int i=arr.size() ; i>2 ; i--){
		int l = 0;
		int r = i-1;
		while(l<r){
			if(arr[l] + arr[r] == arr[i]){
				return true;
			}else{
				arr[l] + arr[r] > arr[i] ? r-- : l++;
			}
		}
	}
	return false;
}

int main(){
	
	vector<int> arr;

	for(int i=0 ; i<4 ; i++){
		arr.push_back(i+1);
	}

	for(int i=0 ; i<arr.size() ; i++){
		arr[i] = arr[i]*arr[i];
	}

	sort(arr.begin(),arr.end());

	if(isTripletPresent(arr)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}