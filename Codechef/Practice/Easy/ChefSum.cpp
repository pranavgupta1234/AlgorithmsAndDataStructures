#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n,0);
		int min_no = 1000000;
		int index = 0;
		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
			if(arr[i] < min_no){
				min_no = arr[i];
				index = i+1;
			}
		}

		cout<<index<<endl;

	}



	return 0;
}