#include <iostream>
#include <vector>

using namespace std;

int main(){

	int n;
	cin>>n;

	int arr[n];
	int odd = 0;
	int even = 0;
	
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
		if(arr[i] & 1){
			cout<<"First"<<endl;
			exit(0);
		}
	}

	cout<<"Second"<<endl;
	return 0;
}
