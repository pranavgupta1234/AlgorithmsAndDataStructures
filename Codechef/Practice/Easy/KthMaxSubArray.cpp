#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){

		int n,m;
		cin>>n>>m;
		int totalSubsets = n*(n+1)/2;
		vector<int> arr(n,0);
		vector<int> subsetsMax(totalSubsets,0);

		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
		}

		int subsetsize = arr.size();

		while(subsetsize >= 1){

			for(int i=0 , j = subsetsize-1 ; i<n and j<n ; i++,j++){
				
			}

		}

		for(int i=0 ; i<m ; i++){


		}


	}


	return 0;
}