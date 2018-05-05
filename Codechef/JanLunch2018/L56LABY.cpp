#include <bits/stdc++.h>

#define ll long long
#define dll long double

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
	ll row;						//row	
	ll col;						//col
	ll dist;
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

void minDistBFS(int n,int m,ll** matrix,Node& source,char** ans){
    bool visited[n][m];
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
            if(matrix[i][j] == -1){
				visited[i][j] = true;
			}else{
				visited[i][j] = false;
			}
		}
	}
    queue<Node> q;
    q.push(source);
	visited[source.row][source.col] = true;
    ans[source.row][source.col] = 'Y';
	while(!q.empty()){
		Node visit = q.front();
		q.pop();
		//move up
		if(visit.row - 1 >= 0 and (visited[visit.row-1][visit.col] == false) and visit.dist>0){
			visited[visit.row-1][visit.col] = true;
			q.push(Node(visit.row-1,visit.col,visit.dist-1));
            ans[visit.row-1][visit.col] = 'Y';
		}
		//move down
		if(visit.row + 1 < n  and (visited[visit.row+1][visit.col] == false) and visit.dist>0){
			visited[visit.row+1][visit.col] = true;
			q.push(Node(visit.row+1,visit.col,visit.dist-1));
            ans[visit.row+1][visit.col] = 'Y';
		}
		//move right
		if(visit.col + 1 < m and (visited[visit.row][visit.col + 1] == false) and visit.dist>0){
			visited[visit.row][visit.col+1] = true;
			q.push(Node(visit.row,visit.col+1,visit.dist-1));
            ans[visit.row][visit.col+1] = 'Y';
		}
		//move left
		if(visit.col - 1 >= 0 and (visited[visit.row][visit.col-1] == false) and visit.dist>0){
			visited[visit.row][visit.col-1] = true;
			q.push(Node(visit.row,visit.col-1,visit.dist-1));
            ans[visit.row][visit.col-1] = 'Y';
		}

	}
}
int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
	    cin>>n>>m;
	    ll** matrix = new ll*[n];
        char** ans = new char*[n];
	    for(int i=0 ; i<n ; i++){
		    matrix[i] = new ll[m];
            ans[i] = new char[m];
	    }
	    for(int i=0 ; i<n ; i++)    for(int j=0 ; j<m ; j++) cin>>matrix[i][j];
        for(int i=0 ; i<n ; i++){
		    for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == -1){
			    	ans[i][j] = 'B';
			    }else{
				    ans[i][j] = 'N';
			    }
		    }
    	}
        
        for(int i=0 ; i<n ; i++){
		    for(int j=0 ; j<m ; j++){
                if(matrix[i][j] > 0) {
                    Node nd = Node(i,j,matrix[i][j]);
                    minDistBFS(n,m,matrix,nd,ans);
                }
		    }
    	}
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}