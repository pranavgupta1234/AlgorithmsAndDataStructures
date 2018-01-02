#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll powers[505];
ll people[505];

int main(){
	ll n,k;
	cin>>n>>k;
	int m = -1;
	for(int i=0 ; i<n ; i++){
		cin>>people[i];
		if(m < people[i]){
			m = people[i];
		}
	}

	if(n >= k){
		for(int i=0 ; i<n-1 ; i++){
			if(people[i] > people[i+1]){
				powers[people[i]]++;
				if(powers[people[i]] == k){
					m = people[i];
					break;
				}	
				people[i+1] = people[i];
			}else{
				powers[people[i+1]]++;
				if(powers[people[i+1]] == k){
					m = people[i+1];
					break;
				}
				people[i] = people[i+1];
			}
		}
	}

	cout<<m<<endl;

	return 0;
}