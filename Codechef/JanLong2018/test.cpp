#include <bits/stdc++.h>

using namespace std;

int main(){
	
	vector<int> arr = { 3 , 5,  7, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	if(lower_bound(arr.begin(),arr.end(),4) == arr.begin()){ cout<<"yo"<<endl;}
	cout<<arr[lower_bound(arr.begin(),arr.end(),4) - arr.begin()-1]<<endl;


	return 0;
}