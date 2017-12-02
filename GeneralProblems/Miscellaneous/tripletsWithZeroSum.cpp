#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int>& arr,int low,int high,int key){

	if(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] == key){
			return true;
		}else if(arr[mid] > key){
			return binarySearch(arr,low,mid-1,key);
		}else{
			return binarySearch(arr,mid+1,high,key);
		}
	}else{
		return false;
	}
}

int main(){

	int t;
	cin>>t;
	
	while(t--){
		int n;
		bool flag = false;
		cin>>n;
		vector<int> arr(n,0);

		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
		}

		for(int i=0 ; i<n ; i++){
			for(int j=i+1 ; j<n ; j++){
				if(binarySearch(arr,0,n-1,(-1)*(arr[i]+arr[j]))){
					flag = true;
					break;
				}
			}
		}

		cout<<(flag ? "Yes" : "No")<<endl;

	}


	return 0;
}