#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

	int max_wt;
	cin >> max_wt;

	vector<int> values = { 1 , 4 , 5 , 7};
	vector<int> weight = { 1 , 3 , 4 , 5};
	set<int> collections;

	int dpmat[values.size()+1][max_wt+1];

	for(int i=0 ; i <= values.size() ; i++){
		dpmat[i][0] = 0;
	}

	for(int i=0 ; i <= max_wt ; i++){
		dpmat[0][i] = 0;
	}

	for(int i=1 ; i <= values.size() ; i++){
		for(int j = 1 ; j <= max_wt ; j++){
			if(weight[i-1] > j){
				dpmat[i][j] = dpmat[i-1][j];
			}else{
				dpmat[i][j] = max(dpmat[i-1][j],(values[i-1]+dpmat[i-1][j-weight[i-1]]));
			}
		}
	}

	/*for(int i=0 ; i <= values.size() ; i++){
		for(int j = 0 ; j <= max_wt ; j++){
			cout<<dpmat[i][j]<<" ";
		}
		cout<<endl;
	}*/

	cout<<"Max Value : "<<dpmat[values.size()][max_wt]<<endl;

	int i = values.size();
	int j = max_wt;

	int temp = 0;

	while(i >= 0 and j>=0 and dpmat[i][j]!=0){
		
		if(temp == max_wt){
			break;
		}

		if(dpmat[i-1][j] != dpmat[i][j]){
			collections.insert(weight[i-1]);
			j = j - weight[i-1];
		}

		i--;
	}

	for(set<int> :: iterator it = collections.begin() ; it != collections.end() ; it++){
		cout<<*it<<" ";
	}

	cout<<endl;

	return 0;
}
