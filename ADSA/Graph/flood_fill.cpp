#include <iostream>
#include <ctime>
using namespace std;

bool dfs(int n,int m,int srcx,int srcy,int destx,int desty,bool** visited,int** matrix);

int main(int argc,char* argv[]){

	if(argc < 3){
		cout<<"Less arguments provided.Please enter nxm size for matrix"<<endl;
		exit(0);
	}

	int n,m;
	int** matrix;
	bool** visited;
	srand(time(0));

	n = atoi(argv[1]);
	m = atoi(argv[2]);

	matrix = new int*[n];
	visited = new bool*[n];

	for(int i=0 ; i<m ; i++){

		matrix[i] = new int[m];
		visited[i] = new bool[m];

	}

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			visited[i][j] = false;
		}
	}

	cout<<"Enter the matrix maze with 0 as blocks which can be visited and 1 which cannot be visited : "<<endl;

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cin>>matrix[i][j];
		}
	}

	int srcx,srcy,destx,desty;

	cout<<"Enter the starting and ending vertex :"<<endl;
	cin>>srcy>>srcx;
	cin>>desty>>destx;

	cout<<(dfs(n,m,srcy,srcx,desty,destx,visited,matrix) ? "Yes" : "No")<<endl;

	return 0;
}

bool dfs(int n,int m,int srcy,int srcx,int desty,int destx,bool** visited,int** matrix){

	if(srcx == destx and srcy == desty){
		return true;
	} 

	if(srcx >= m or srcy>= n){
		return false;
	}

	if(srcx < 0 or srcy < 0){
		return false;
	}

	if(visited[srcy][srcx] == true){
		return false;
	}

	if(matrix[srcy][srcx] == 1){
		return false;
	}

	visited[srcy][srcx] = true;
	cout<<srcy<<" "<<srcx<<endl;

	int random_bit_1 = rand()%2;
	int random_bit_2 = 1 - random_bit_1;

	if(dfs(n,m,srcy + random_bit_1,srcx + random_bit_2,desty,destx,visited,matrix) == true){
		return true;
	}
	if(dfs(n,m,srcy - random_bit_1,srcx - random_bit_2,desty,destx,visited,matrix) == true){
		return true;
	}
	if(dfs(n,m,srcy + random_bit_2 , srcx + random_bit_1,desty,destx,visited,matrix) == true){
		return true;
	}
	if(dfs(n,m,srcy - random_bit_2 , srcx - random_bit_1,desty,destx,visited,matrix) == true){
		return true;
	}

	return false;
}