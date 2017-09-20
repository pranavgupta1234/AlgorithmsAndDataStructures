#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){
		int n,k;
		cin>>n>>k;

		int kCopy = k; 

		map<int,int> factors;

		while(kCopy%2 == 0){
			factors[2]++;
			kCopy/=2;
		}

		for(int i=3 ; i*i<=kCopy ; i+=2){
			while(kCopy % i == 0){
				factors[i]++;
				kCopy/=i;
			}
		}

		if(kCopy > 2){
			factors[kCopy]++;
		}

		int minNoOfFactors = 1000000;

		for(map<int,int> :: iterator it = factors.begin() ; it != factors.end() ; it++){

			int j=1;
			int maxPower = 0;
			int factor = it -> first;
			int power = it -> second;

			while(n > pow(factor,j)){
				maxPower += n/pow(factor,j); 
				j++;
			}

			maxPower /= power;

			minNoOfFactors = min(minNoOfFactors,maxPower);
		}

		cout<<minNoOfFactors<<endl;


	}

	return 0;
}