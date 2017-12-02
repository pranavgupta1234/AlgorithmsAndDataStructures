#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int maxSumofLengthOfSubArrays(int* arr,int k,int n){
	int ans = 0;
	int count = 0;
	bool flag = false;
	for(int i=0 ; i<n ;){
		count = 0;
		flag = false;
		while(arr[i] <= k and i < n){
			count++;
			if(arr[i] == k){
				flag = true;
			}
			i++;
		}
		if(flag == true){
			ans += count;
		}
		while(arr[i]>k and i<n){
			i++;
		}
	}
	return ans;
}

int main(){
	int n,k;
	cin>>n;
	cin>>k;
	int arr[n];
	memset(arr,0,sizeof(arr[0])*n);
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}
	cout<<maxSumofLengthOfSubArrays(arr,k,n);
	cout<<endl;
	return 0;
}