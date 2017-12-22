#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

#define range 10000

int main(){
	
	bool isprime[range];
	int freqvisit[range];
	vector<int> lucky;
	memset(isprime,true,sizeof(isprime[0])*range);
	memset(freqvisit,0,sizeof(freqvisit[0])*range);
	isprime[0] = isprime[1] = false;
	for(int i=2 ; i<=range ; i++){
		if(isprime[i]){
			for(int j=2*i ; j<=range ; j+=i){
				isprime[j] = false;
				freqvisit[j] += 1;
				//as soon as it consists of 3 prime factors we capture it in our array
				if(freqvisit[j] == 3){
					//cout<<i<<endl;
					lucky.push_back(j);
				}
			}
		}
	}
	sort(lucky.begin(),lucky.end());
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<lucky[n-1]<<endl;
	}
	return 0;
}