#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

#define range 100010

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int hash_initial[range];
	int hash_final[range];
	memset(hash_final,0,sizeof(hash_final[0])*range);
	memset(hash_initial,0,sizeof(hash_initial[0])*range);
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
		hash_initial[arr[i]] = i;
	}
	sort(arr,arr+n);
	for(int i=0 ; i<n ; i++){
		hash_final[arr[i]] = i;
	}
	//for(int i=0 ; i<n ; i++){
	//	cout<<hash_initial[arr[i]]<<" "<<hash_final[arr[i]]<<endl;
	//}
	//cout<<endl;
	int replace = -INT_MAX;
	int valreplacable = INT_MAX;
	for(int i=0 ; i<n ; i++){
		if(abs(hash_final[arr[i]] - hash_initial[arr[i]]) >= replace){
			replace = abs(hash_final[arr[i]] - hash_initial[arr[i]]);
			valreplacable = arr[i];
		}
	}
	//for(int i=0 ; i<n ; i++){
	//	if(abs(hash_final[arr[i]] - hash_initial[arr[i]]) == replace and arr[i] < valreplacable){
	//		valreplacable = arr[i];
	//	}
	//}
	cout<<valreplacable<<endl;
	return 0;
}