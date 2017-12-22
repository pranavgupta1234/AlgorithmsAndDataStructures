#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
	int row;						//row	
	int col;						//col
	int dist;

	Node(int row,int col,int z){
		this -> row = row;
		this -> col = col;
		this -> dist = z;
	}
};

/*
Given a matrix of N*M order. Find the shortest distance from a source cell to a destination cell, traversing through 
limited cells only. Also you can move only up, down, left and right. If found output the distance else -1.
*/

int minDistBFS(int n,int m,char** matrix){
	Node source(0,0,0);
	bool visited[n][m];

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			if(matrix[i][j] == '0'){
				visited[i][j] = true;
			}else{
				visited[i][j] = false;
			}

			if(matrix[i][j] == 's'){
				source.row = i;
				source.col = j;
				source.dist = 0;
			}
		}
	}

	queue<Node> q;
	q.push(source);
	matrix[source.row][source.col] = 0;
	while(!q.empty()){

		Node visit = q.front();
		q.pop();
		if(matrix[visit.row][visit.col] == 'd'){
			return visit.dist;	
		}

		//move up
		if(visit.row - 1 >= 0 and visited[visit.row-1][visit.col] == false){
			visited[visit.row-1][visit.col] = true;
			q.push(Node(visit.row-1,visit.col,visit.dist+1));
		}
		//move down
		if(visit.row + 1 < n  and visited[visit.row+1][visit.col] == false){
			visited[visit.row+1][visit.col] = true;
			q.push(Node(visit.row+1,visit.col,visit.dist+1));
		}

		//move right
		if(visit.col + 1 < m and visited[visit.row][visit.col + 1] == false){
			visited[visit.row][visit.col+1] = true;
			q.push(Node(visit.row,visit.col+1,visit.dist+1));
		}

		//move left
		if(visit.col - 1 >= 0 and visited[visit.row][visit.col-1] == false){
			visited[visit.row][visit.col-1] = true;
			q.push(Node(visit.row,visit.col-1,visit.dist+1));
		}

	}
	
	return -1;
}

int main(){
	int n,m;
	cin>>n>>m;
	char** matrix = new char*[m];
	for(int i=0 ; i<n ; i++){
		matrix[i] = new char[m];
	}
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cin>>matrix[i][j];
		}
	}
	cout<<minDistBFS(n,m,matrix)<<endl;
	return 0;
}