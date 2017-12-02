#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int n,m;
	cin>>n>>m;

	int mat[n][m];
	memset(mat,0,n*m);
	bool visits[n][m];
	memset(visits,false,false);

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cin>>mat[i][j];
		}
	}

	int k = 0;		 //starting col index
	int p = 0;		 //starting row index
	
	while(k < n and p < m){

		for(int i=k ; i<n ; i++){
			cout<<mat[p][i]<<" ";
		}

		p++;

		for(int i=p ; i<m ; i++){
			cout<<mat[i][m-1]<<" ";
		}

		n--;

		if(p < n){
			
		}


	}
	

	
}