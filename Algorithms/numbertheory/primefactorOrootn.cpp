#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define uom unordered_map
#define range 10000007

using namespace std;

vector<int> factors;
int spf[range];

void seive(){
	for(int i=0 ; i<range ; i++){
		spf[i] = i;
	}

	for(int i=2 ; i<range ; i+=2){
		spf[i] = 2;
	}

	for(int i=3 ; i*i<range ; i++){
		if(spf[i] == i){
			for(int j=2*i ; j<range ; j+=i){
				if(spf[j] == j){
					spf[j] = i;
				}
			}
		}
	}
} 

void generateFactors(int n){
	while(n != 1){
		factors.push_back(spf[n]);
		n /= spf[n];
	}
}

int main(){
	int n;
	cin>>n;

	seive();
	factors.clear();
	generateFactors(n);

	for(int i=0 ; i < factors.size() ; i++){
		cout<<factors[i]<<" ";
	}
	cout<<endl;
	return 0;
}