#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n,k;

ll maxsum(ll a[],ll size){
	ll max_so_far = a[0];
	ll curr_max = a[0];
	for (int i = 1; i < size; i++){
		curr_max = max(a[i], curr_max+a[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	return max_so_far;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		ll arr[2*n+5];
		ll actsum = 0;
		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
			actsum += arr[i];
			arr[n+i] = arr[i];	
		}
		if(k == 1) cout<<maxsum(arr,n)<<endl;
		else{
			ll mxsum = maxsum(arr,2*n);
			if(mxsum <= 0 or actsum <=0)	cout<<mxsum<<endl; 
			else cout<<mxsum + (k-2)*actsum<<endl;
		} 
	}
	return 0;
}