#include <bits/stdc++.h>

#define ll long long

using namespace std;

inline ll maxsum(int a[], int size){
   int max_so_far = a[0];
   int curr_max = a[0];
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
		int n,k;
		cin>>n>>k;
		int arr[k*n];
		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
			for(int j=1 ; j<=k-1 ; j++){
				arr[i+j*n] = arr[i];
			}
		}

		cout<<maxsum(arr,k*n)<<endl;
	}

	return 0;
}