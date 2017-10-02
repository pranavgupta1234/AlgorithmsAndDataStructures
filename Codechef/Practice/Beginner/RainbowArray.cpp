#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main(){	

	int t;
	cin>>t;

	while(t--){

		bool flag = true;
		int n;
		cin>>n;
		int hash[8];

		for(int i=0 ; i<8 ; i++){
			hash[i] = 0;
		}

		vector<int> arr(n,0);

		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
			hash[arr[i]]++;
			if(arr[i] > 7){
				flag = false;
				break;
			}
		}

		for(int i=1 ; i<8 ; i++){
			if(hash[i] < 1){
				flag = false;
				break;
			}
		}

		if(flag){

			if(n&1){

				int left = n/2 - 1;
				int right = n/2 + 1;

				while(left > 0 and right < n){

					if(arr[left] == arr[right] and arr[left-1] <= arr[left] and arr[right] >= arr[right+1]){
						left--;
						right++;
						continue;
					}else{
						flag = false;
						break;
					}
				}

			}else{

				int left = n/2 - 1;
				int right = n/2 ;

				while(left > 0 and right < n - 1){

					if(arr[left] == arr[right] and arr[left-1] <= arr[left] and arr[right] >= arr[right+1]){
						left--;
						right++;
						continue;
					}else{
						flag = false;
						break;
					}
				}

			}

		}

		cout<<(flag ? "yes" : "no")<<endl;

	}

	return 0;
}