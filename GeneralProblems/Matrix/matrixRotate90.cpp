#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void transposeMatrix(int* mat,int n,int m){
	int k;
	for(int i=0 ; i<n ; i++){
		for(int j=i ; j<m ; j++){
			swap(*(mat + i*n + j),*(mat + j*n + i));
		}
	}
}

void reverseRowForClockwise(int* mat,int n,int m){
	int k;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ,k = m-1; j<k ; j++,k--){
			swap(*(mat + i*n + j),*(mat + i*n + k));
		}
	}
}

void reverseColForAntiClockwise(int* mat,int n,int m){
	int k;
	for(int i=0 ; i<m ; i++){
		for(int j=0 ,k = n-1 ; j<k ; j++,k--){
			swap(*(mat + i*n + j),*(mat + i*n + k));
		}
	}
}

void print(int* mat,int n,int m){
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cout<<*(mat + i*n + j)<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	int mat[n][m];
	memset(mat,0,sizeof(mat[0][0])*n*m);
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cin>>mat[i][j];
		}
	}

	transposeMatrix((int*)mat,n,m);

	reverseRowForClockwise((int*)mat,n,m);

	print((int*)mat,n,m);

	return 0;
}