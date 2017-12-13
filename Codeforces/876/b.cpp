#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	int n,k,p;
	cin>>n>>k>>p;
	int arr[n];
	int count = 0;
	int flag = false;
	//as we have to take modulo p hence max remainder is p-1
	int hash_modulo[p];
	memset(hash_modulo,0,sizeof(hash_modulo[0])*p);
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}
	/*
	If x - y is divisible by m, then x and y have same reminder when divided by m.
	Let's divide number to groups by reminder by modulo m, 
	and if there is a group with size at least k print k numbers from it. 
	*/
	for(int i=0 ; i<n ; i++){
		hash_modulo[arr[i]%p]++;
	}	
	int suitablemod = 0;
	for(int i=0 ; i<p ; i++){
		if(hash_modulo[i] >= k){
			suitablemod = i;
			flag = true;
			break;
		}
	}
	if(flag){
		cout<<"Yes"<<endl;
		int i = 0;
		while(k){
			if(arr[i] % p == suitablemod){
				cout<<arr[i]<<" ";
				k--;
			}
			i++;
		}
		cout<<endl;
	}else{
		cout<<"No"<<endl;;
	}
	return 0;
}