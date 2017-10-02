#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;
		vector<int> arr(n,0);

		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
		}

		auto it = min_element(arr.begin(),arr.end());

		cout<<(*it)*(arr.size()-1)<<endl;

	}

	return 0;
}