#include <iostream>
#include <vector>

using namespace std;

void printSubset(vector<int>& set,int sum){

	int setsize = set.size();
	bool DPmat[setsize+1][sum+1];

	for(int i=0 ; i<=setsize ; i++){
		DPmat[i][0] = true;
	}

	for(int i=1 ; i<=sum ; i++){
		DPmat[0][i] = false;
	}	

	for(int i=1 ; i<=setsize ; i++){
		for(int j=1 ; j<=sum ; j++){
			if(set[i-1] > j){
				DPmat[i][j] = DPmat[i-1][j];
			}else{
				DPmat[i][j] = DPmat[i-1][j] or DPmat[i-1][j - set[i-1]]; 
			}
		}
	}

	cout<<(DPmat[setsize][sum] ? "YES" : "NO")<<endl;

	// for(int i=0 ; i<=setsize ; i++){
	// 	for(int j=0 ; j<=sum ; j++){
	// 		cout<<DPmat[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

}

int main(){
	
	vector<int> set = {2 , 3, 7 , 8 , 10};
	int sum = 11;
	printSubset(set,sum);
	return 0;
}