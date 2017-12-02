#include <iostream>
#include <vector>

using namespace std;

int main(){

	int n;
	cin>>n;

	vector<int> arr(n,0);

	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}

	int maxNew = arr[0];
	int maxSoFar = arr[0];

	for(int i=1 ; i<n ; i++){
		maxNew = max(maxNew+arr[i],arr[i]);
		maxSoFar = max(maxSoFar,maxNew);
	}

	cout<<maxSoFar<<endl;

	return 0;
}