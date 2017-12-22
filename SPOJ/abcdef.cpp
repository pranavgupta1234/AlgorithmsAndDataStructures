#include <iostream>
#include <vector>	
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

bool binary_search(int arr[],int low,int high,int key){
	if(low <= high){	
		int mid = low + (high-low)/2;
		if(arr[mid] == key){
			return true;
		}else if(arr[mid] > key){
			return binary_search(arr,low,mid-1,key);
		}else{
			return binary_search(arr,mid+1,high,key);
		}
	}else{
		return false;
	}
}

int main(){
	//n <= 100
	int n;
	cin>>n;
	int arr[n];
	vector<int> lhs;
	vector<int> rhs;	
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			for(int k=0 ; k<n ; k++){
				lhs.push_back(arr[i]*arr[j] + arr[k]);
				if(arr[k] != 0){
					rhs.push_back((arr[i]+arr[j])*arr[k]);
				}
			}
		}
	}
	long long total = 0; 
	sort(lhs.begin(),lhs.end());
	sort(rhs.begin(),rhs.end());
	for(int i=0 ; i<lhs.size() ; i++){
		int lower = lower_bound(rhs.begin(),rhs.end(),lhs[i]) - rhs.begin();
		int higher = upper_bound(rhs.begin(),rhs.end(),lhs[i]) - rhs.begin();
		total += abs(higher - lower);
	}
	cout<<total<<endl;
	return 0;
}