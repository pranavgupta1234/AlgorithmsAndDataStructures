#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#define endl "\n"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		unsigned long long sum = 0;
		int n,p;
		cin>>n>>p;
		int easy = 0;
		int hard = 0;
		int hard_lim = p/10;
		int easy_lim = p/2;
		int arr[n];
		memset(arr,0,n);
		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
		}

		for(int i=0 ; i<n ; i++){
			if(arr[i] <= hard_lim){
				hard++;
			}
			if(arr[i] >= easy_lim){
				easy++;
			}

			if(easy > 1 or hard > 2){
				break;
			}
		}

		if(easy == 1 and hard == 2){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}

	return 0;
}