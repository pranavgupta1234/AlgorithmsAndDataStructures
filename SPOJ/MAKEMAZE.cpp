#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n,m;

string isValid(char maze[n][m],int sourcex,int sourcey){
	bool visited[n][m];
	memset(visited,false,sizeof(visited[0][0])*n*m);

}

int main(){
	cin>>n>>m;
	char maze[n][m];
	memset(maze,0,sizeof(maze[0][0])*n*m);
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cin>>maze[i][j];
			if(maze[i][j] == '.'){
				sourcex = i;
				sourcey = j;
			}
		}
	}

	cout<<isValid(maze,sourcex,sourcey)<<endl;

	return 0;
}