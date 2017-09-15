#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int n;

	cin>>n;

	//sieve of eratosthenos
	vector<bool> sieverat(n+1,true);
	vector<int> nums(n+1,0);

	for(int i=2 ; i*i<=n ; i++){

		if(sieverat[i] == true){
			for(int j=2*i ; j<=n ; j+=i){
				sieverat[j] = false;
				nums[j] = i;
			}
		}
	}

	for(int i=2 ; i<=n ; i++){
		if(!nums[i]){
			nums[i] = i;
		}
	}

	/*
		Essentially it boils down to if your number n is:
		n = a^x * b^y * c^z
		(where a, b, and c are n's prime divisors and x, y, and z are the number of times that divisor is repeated) 
		then the total count for all of the divisors is:
		(x + 1) * (y + 1) * (z + 1).
	*/

	int curr = nums[n];
	int cnt = 1;
	int divisors = 1;

	while(n>1){

		n /= nums[n];

		if(curr == nums[n]){
			cnt++;
			continue;
		}

		divisors *= (cnt+1);

		curr = nums[n];
		cnt = 1;

	}

	cout<<divisors<<endl;

	return 0;
}

//this finds in O(logn)