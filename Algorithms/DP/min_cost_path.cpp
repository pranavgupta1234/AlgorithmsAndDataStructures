#include <bits/stdc++.h>
using namespace std;
int minCostPath(int cost[][3],int m,int n);
int main(){
    int cost[3][3]= { {1,2,3},
                      {4,8,2},
                      {1,5,3}
                    };
    cout<<minCostPath(cost,3,3)<<endl;                
	return 0;
}
int minCostPath(int cost[][3],int a,int b){
	int m=3;
	int n=3;
	int minCost[m][n];
    int path=0;
    int j;
    for(int i=0;i<m;i++){
    	j=0;
    	path = path+cost[i][j];
    	minCost[i][0] = path;
    }
    path =0;
    for(int i=0;i<n;i++){
    	j=0;	
    	path+=cost[j][i];
    	minCost[0][i]= path;
    }
    for(int i=1;i<m;i++){
    	for(int j=1;j<n;j++){
    		minCost[i][j] = cost[i][j] + min(minCost[i-1][j],min(minCost[i-1][j-1],minCost[i][j-1]));
    	}
    }
    for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    		cout<<minCost[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return minCost[m-1][n-1];
}