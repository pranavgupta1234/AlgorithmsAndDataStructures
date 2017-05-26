#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
	
	vector<int> arr;
	int sum,temp;

	for(int i=0 ; i<5 ; i++){
		cin>>temp;
		arr.push_back(temp);
	}

	cin>>sum;

	bool dpTable[arr.size()][sum+1];

	memset(dpTable,true,arr.size()*(sum+1)*sizeof(bool));

	for(int j=1 ; j <=sum ; j++){
		if(j != arr[0]){
			dpTable[0][j] = false;
		}
	}

	for(int i=0 ; i< arr.size() ; i++){
		for(int j=1 ; j<=sum ; j++){
			if(arr[i] > j){
				dpTable[i][j] = dpTable[i-1][j];
			}else{
				if(dpTable[i-1][j] == true){
					dpTable[i][j] = true;
				}else{
					dpTable[i][j] = dpTable[i-1][j-arr[i]];
				}

			}
		}
	}

	dpTable[arr.size()-1][sum] ? cout<<"YES"<<endl : cout<<"NO"<<endl ;

	return 0;
}