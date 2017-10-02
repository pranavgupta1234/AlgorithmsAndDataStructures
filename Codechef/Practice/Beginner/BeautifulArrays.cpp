#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
	
	int t;
	cin>>t;

	while(t--){

		bool flag = true;
		ll n;
		cin>>n;

		vector<ll> arr(n,0);

		for(ll i=0 ; i<n ; i++){
			cin>>arr[i];
		}
		int ones = 0;
		int zeroes = 0;
		int minusOnes = 0;
		int other = 0;

		for(int i=0 ; i<n ; i++){
			if(arr[i] == 1){
				ones++;
			}else if(arr[i] == -1){
				minusOnes++;
			}else if(arr[i] == 0){
				zeroes++;
			}else{
				other++;
			}
		}

		if(other > 1){
			flag = false;
		}else if(minusOnes and other){
			flag = false;
		}else if(ones == 0 and minusOnes > 1){
			flag = false;
		}

		cout<<(flag ? "yes" : "no");
		cout<<endl;
	}

	return 0;
}