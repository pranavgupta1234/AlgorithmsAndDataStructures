#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){

		int no_of_items;
		int max_cap;
		int temp;
		vector<int> values;
		vector<int> weights;
		
		cin>>no_of_items;
		cin>>max_cap;
		int sum=0;

		int dp[no_of_items+1][max_cap+1];

		for(int i=0 ; i<no_of_items ; i++){
			cin>>temp;
			values.push_back(temp);
		}

		for(int i=0 ; i<no_of_items ; i++){
			cin>>temp;
			weights.push_back(temp);
		}

		for(int i=0 ; i<=no_of_items ; i++){
			dp[i][0] = 0;
		}

		for(int i=0 ; i<=max_cap ; i++){
			dp[0][i] = 0;
		}

		for(int i=1 ; i<=no_of_items ; i++){
			for(int j=1 ; j<=max_cap ; j++){

				if(weights[i-1] > j){
					dp[i][j] = dp[i-1][j];
				}else {
					dp[i][j] = max(dp[i-1][j],(values[i-1] + dp[i-1][j-weights[i-1]]));
				}
			}
		}

		cout<<dp[no_of_items][max_cap]<<endl;

	}	

	return 0;
}