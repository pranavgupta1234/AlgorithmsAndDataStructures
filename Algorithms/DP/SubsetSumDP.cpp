#include <bits/stdc++.h>
using namespace std;
bool isSubsetSum(vector<int> &set,int n,int sum);
int main(){
    vector<int> a = {1,3,9,2};
    int sum = 5;
    if(isSubsetSum(a,a.size(),sum)){
    	cout<<"SubSet Found"<<endl;
    }
    else{
    	cout<<"No SubSet Exists"<<endl;
    }
	return 0;
}
bool isSubsetSum(vector<int> &set, int n,int sum){
    
    bool subset[sum+1][n+1];

    for(int i=1;i<=sum;i++){
    	subset[i][0] = false;
    }

    for(int i=0;i<=n;i++){
    	subset[0][i] = true;
    }

    for(int i=1;i<=sum;i++){
    	for(int j=1;j<=n;j++){
    		subset[i][j] = subset[i][j-1];
    		if(i>=set[j-1])
    		subset[i][j] = subset[i][j]||subset[i-set[j-1]][j-1];
    	}
    }
    /*
    for(int i=0;i<=sum;i++){
    	for(int j=0;j<=n;j++){
    		cout<<subset[i][j]<<" ";
    	}
    	cout<<endl;
    }
    */
    return subset[sum][n];
}