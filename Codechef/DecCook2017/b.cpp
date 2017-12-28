#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll sum = 0;
ll sum4 = 0;
ll len = 0;
ll len4 = 0;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
			if(arr[i] % 4 == 0){
				sum4 += arr[i];
				len4++;
			}else{
				sum += arr[i];
				len++;
			}
		}
		sort(arr,arr+n);
		if(sum % 4 != 0){
			cout<<"-1"<<endl;
		}else{
			ll dumsum = 0;
			ll temp  = 0;
			int i = 0 ;
			int j = n-1;
			int steps = 0;
			while(i<j){
				if((arr[i]+arr[j])%4 == 0){
					dumsum += arr[i]+arr[j];
					i++;
					j--;
					steps++;
				}else{
					temp += arr[i]+arr[j];
					j--;
				}
			}
			cout<<steps<<endl;
		}
	}

	return 0;
}