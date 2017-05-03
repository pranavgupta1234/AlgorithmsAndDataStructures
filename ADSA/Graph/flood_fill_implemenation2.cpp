#include <iostream>
#include <ctime>
using namespace std;

bool dfs(int n,int m,int srcx,int srcy,int destx,int desty,bool** visited,int** matrix,char** final_matrix);
bool allVisited(int* flag);


int main(int argc,char* argv[]){

	if(argc < 3){
		cout<<"Less arguments provided.Please enter nxm size for matrix"<<endl;
		exit(0);
	}

	int n,m;
	int** matrix;
	char** final_matrix;
	bool** visited;
	srand(time(0));

	n = atoi(argv[1]);
	m = atoi(argv[2]);

	matrix = new int*[n];
	final_matrix = new char*[n];
	visited = new bool*[n];

	for(int i=0 ; i<m ; i++){

		matrix[i] = new int[m];
		visited[i] = new bool[m];
		final_matrix[i] = new char[m];
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
			final_matrix[i][j] = (matrix[i][j] == 0 ? '0' : '1');
		}
	}

	int srcx,srcy,destx,desty;

	cout<<"Enter the starting and ending vertex :"<<endl;
	cin>>srcy>>srcx;
	cin>>desty>>destx;

	cout<<(dfs(n,m,srcy,srcx,desty,destx,visited,matrix,final_matrix) ? "Yes" : "No")<<endl;

	final_matrix[desty][destx] = 'P';
	for(int i=0 ; i<n ; i++){
		for(int  j=0 ; j<m ; j++){
			cout<<final_matrix[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

bool dfs(int n,int m,int srcy,int srcx,int desty,int destx,bool** visited,int** matrix,char** final_matrix){

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

	int* flags = new int[8];

	for(int i=0 ; i<8 ; i++){
		flags[i] = 0;
	}

	while(!allVisited(flags)){

		int r = rand()%8;

		if(flags[r] == 1){
			continue ;
		}

		flags[r] = 1;


		switch(r){

			case 0 : 

				if(dfs(n,m,srcy , srcx + 1,desty,destx,visited,matrix,final_matrix) == true){
					final_matrix[srcy][srcx] = 'P';
					return true;
				}
				break;

			case 1 :

				if(dfs(n,m,srcy , srcx - 1 ,desty,destx,visited,matrix,final_matrix) == true){
					final_matrix[srcy][srcx] = 'P';
					return true;
				}	
				break;

			case 2 : 
			
				if(dfs(n,m,srcy - 1, srcx + 1 ,desty,destx,visited,matrix,final_matrix) == true){
					final_matrix[srcy][srcx] = 'P';
					return true;
				}
				break;
			
			case 3 : 
			
				if(dfs(n,m,srcy - 1, srcx - 1 ,desty,destx,visited,matrix,final_matrix) == true){
					final_matrix[srcy][srcx] = 'P';
					return true;
				}
				break;
			
			case 4 : 
				
				if(dfs(n,m,srcy -1 , srcx ,desty,destx,visited,matrix,final_matrix) == true){
					final_matrix[srcy][srcx] = 'P';
					return true;
				}
				break;
			
			case 5 : 
				
				if(dfs(n,m,srcy + 1, srcx - 1 ,desty,destx,visited,matrix,final_matrix) == true){
					final_matrix[srcy][srcx] = 'P';
					return true;
				}
				break;
			
			case 6 : 
				
				if(dfs(n,m,srcy + 1, srcx + 1 ,desty,destx,visited,matrix,final_matrix) == true){
					final_matrix[srcy][srcx] = 'P';
					return true;
				}
				break;
			
			case 7 : 
			
				if(dfs(n,m,srcy + 1, srcx ,desty,destx,visited,matrix,final_matrix) == true){
					final_matrix[srcy][srcx] = 'P';
					return true;
				}
				break;
		}

	}

	return false;
}

bool allVisited(int* flag){

	for(int i=0 ; i<8 ; i++){
		if(flag[i] == 0){
			return false;
		}
	}

	return true;
}