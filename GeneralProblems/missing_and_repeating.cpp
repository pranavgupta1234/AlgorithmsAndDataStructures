#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(int a,int l,int r,vector<int>& arr);

int main(){

	vector<int> arr = {1,3,3};
	int miss=0;
	int rep=0;
	sort(arr.begin(),arr.end());

	for(int i=1 ; i<arr.size() ; i++){
		if(arr[i]==arr[i-1]){
			rep = arr[i];
		}
		if(arr[i]-arr[i-1]!=1){
			miss = arr[i]-1;
		}

		if(miss and rep){
			cout<<rep<<" "<<miss<<endl;
			exit(0);
		}
	}

	return 0;
}

bool binary_search(int a,int l,int r,vector<int>& arr){

	if(l<=r){

		int mid = l + (r-l)/2;

		if(arr[mid] == a){
			return true;
		}else if(arr[mid] > a){
			return binary_search(a,l,mid-1,arr);
		}else if(arr[mid] < a){
			return binary_search(a,mid+1,r,arr);
		}
	}else {
		return false;
	}

}