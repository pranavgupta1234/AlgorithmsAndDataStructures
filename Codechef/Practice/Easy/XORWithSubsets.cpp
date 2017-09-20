#include <iostream>
#include <vector>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n,k;
		cin>>n>>k;

		vector<int> arr(n,0);

		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
		}

		int dpmat[arr.size()+1][1024];

		dpmat[0][0] = 1;

		for(int i=1 ; i<1024 ; i++){
			dpmat[0][i] =  0;
		}



		for(int i=1 ; i<=arr.size() ; i++){
			for(int j=0 ; j<1024 ; j++){
				dpmat[i][j] = dpmat[i-1][j] | dpmat[i-1][j^arr[i-1]];
			}
		}

		int maxVal = 0;

		for(int i=0 ; i<1024 ; i++){
			maxVal = max(maxVal,dpmat[arr.size()][i]*(i^k));
		}

		cout<<maxVal<<endl;


	}


	return 0;
}