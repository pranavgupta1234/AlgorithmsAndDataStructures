#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int arr[100010];

int main(){
	int n,d;
	cin>>n>>d;
	ll sum = 0;
	ll days = 0;
	bool poss = false;
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
		if(arr[i] == 0 and sum < 0){
			days++;
		}else{
			sum += arr[i];
		}

		if(sum > d){
			poss = true;
		}
	}	

	if(poss){
		cout<<"-1"<<endl;
	}else{
		cout<<days<<endl;
	}

	return 0;
}
						