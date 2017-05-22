#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

unsigned int brute_force_sum(vector<int>& a);
unsigned int eff_sum(vector<int>& a);

int main(){
	
	vector<int> a(10);

	for(int i=0 ; i<10 ; i++){
		a[i] = i;
	}

	cout<<"Sum of all subsequences(Brute force Approach O(2^n)) : "<<brute_force_sum(a)<<endl;

	cout<<"Sum of all subsequences(Efficient O(n)) : "<<eff_sum(a)<<endl;

	return 0;
}

unsigned int brute_force_sum(vector<int>& a){

	unsigned int sum = 0;

	for(int i=0 ; i<pow(2,a.size()) ; i++){

		for(int j=0 ; j< a.size() ; j++){

			if(i&(1<<j)){
				sum += a[j];
			}
		}

	}

	return sum;
}

unsigned int eff_sum(vector<int>& a){
	
	unsigned int sum = 0;

	for(int i=0 ; i<a.size() ; i++){
		sum += a[i];
	}

	return (unsigned int)sum*pow(2,a.size()-1);
}
