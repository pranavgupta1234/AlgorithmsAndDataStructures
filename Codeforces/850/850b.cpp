#include <iostream>
#include <vector>

#define INT_MAX 100000000
using namespace std;

int main(){

	int n,x,y;
	cin>>n>>x>>y;
	int max_element = 0;
	int min_cost = INT_MAX;
	vector<int> nums(n,0);
	
	for(int i=0 ; i<n ; i++){
		cin>>nums[i];
		max_element = max(max_element,nums[i]);
	}

	for(int i=2 ; i<=max_element ; i++){
		int minCostForGCDi = 0;
		for(int j=0 ; j<nums.size() ; j++){
			minCostForGCDi += min(x,y*((nums[j]/i + 1)*i - nums[j]));
		}
		//cout<<i<<" "<<minCostForGCDi<<endl;
		min_cost = min(min_cost,minCostForGCDi);
	}

	cout<<min_cost<<endl;

	return 0;
}