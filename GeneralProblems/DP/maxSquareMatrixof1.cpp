#include <iostream>
#include <vector>
#define n 5
#define m 5

using namespace std;

int maxSubSQR(int arr[n][m]);

int main(){

	int mat[n][m];

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cin>>mat[i][j];
		}
	}

	cout<<maxSubSQR(mat)<<endl;


	return 0;
}

int maxSubSQR(int mat[n][m]){

	int dpmat[n][m];
	//dpmat[i][j] represents max subsquare matrix attained till i,j 
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			if(i==0 or j==0){
				dpmat[i][j] = mat[i][j];
			}else{
				if(mat[i][j] == 1){
					dpmat[i][j] = 1 + min(dpmat[i-1][j-1],min(dpmat[i-1][j],dpmat[i][j-1]));
				}else{
					dpmat[i][j] = 0;
				}
			}
		}
	}

	cout<<endl<<endl;

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cout<<dpmat[i][j]<<" ";
		}
		cout<<endl;
	}

	return dpmat[n-1][m-1];

}