#include <iostream>
#include <vector>
#include <map>

#define mod 1000000007

using namespace std;

void execCommand(vector<long long int>& arr,long long int start,long long int end,vector<long long int>& res){
	for(long long int i=start ; i<=end ; i++){
		arr[i] = (arr[i]+1)%mod;
		res[i] += arr[i];
	}	
}

void addArray(vector<long long int>& arr1,vector<long long int>& arr2,vector<long long int>& res){
	for(long long int i=0 ; i<arr1.size() ; i++){
		if(arr2[i] != 0){
			arr1[i] = (arr1[i] + arr2[i])%mod;
			res[i] += arr1[i];
		}			
	}
}

int main(){
	
	int t;
	cin>>t;
	while(t--){

		int n,m;
		cin>>n>>m;
		vector<long long int> resultant_array(n+1,0);
		vector< vector<long long int> > command_individual_effect(m+1,vector<long long int>(n+1));			//initialises a 2d vector with default val 0 

		for(int i=1 ; i<=m ; i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a == 1){
				execCommand(command_individual_effect[i],b,c,resultant_array);
			}else{
				for(int j=b ; j<=c ; j++){
					addArray(command_individual_effect[i],command_individual_effect[j],resultant_array);					
				}
				//addArray(resultant_array,command_individual_effect[i]);
			}
		}

		for(int i=1 ; i<=n ; i++){
			cout<<resultant_array[i]<<" ";
		}

		cout<<endl;
	}

	return 0;
}