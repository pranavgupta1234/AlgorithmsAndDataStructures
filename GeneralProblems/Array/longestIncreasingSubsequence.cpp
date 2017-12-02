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
		vector<int> dparr(n,1);
		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
		}
		for(int i=1 ; i<n ; i++){
			for(int j=0 ; j<i ; j++){
				if(arr[i] > arr[j] and dparr[i] < (dparr[j] + 1)){
					dparr[i] = dparr[j] + 1;
				}
			}
		}

		int maxval = 0;

		for(int i=0 ; i<n ; i++){
			if(dparr[i] > maxval){
				maxval = dparr[i];
			}
		}

		if(n==1){
			maxval = 0;
		}
		
		cout<<maxval<<endl;
	}

	return 0;
}