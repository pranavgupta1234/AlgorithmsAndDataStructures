#include <iostream>
#include <vector>

#define ll long long 

using namespace std;

int main(){
	
	ll t;
	cin>>t;

	while(t--){

		ll n;
		cin>>n;

		vector<ll> arr(n,0);

		for(ll i=0 ; i<n ; i++){
			cin>>arr[i];
		}

		//for a sorted array of length n there are n(n-1)/2 increasing subarrays in it
		ll count = 0;
		
		for(ll i=0 ; i< arr.size() -1 ; i++){	

			ll len = 1;
			ll j = i+1;

			while (arr[j] >= arr[j-1] and j<arr.size()){
				len++;
				j++;
			}
			count+=len*(len+1)/2;
		}

		cout<<count<<endl;

	}



	return 0;
}