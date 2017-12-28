#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	char board[10][10];
	int x,y;
	for(int i=1 ; i<= 9 ; i++){
		for(int j=1 ; j<= 9 ; j++){
			cin>>board[i][j];
		}
	}
	cin>>x>>y;
	int actx,acty;
	if(x%3 == 0){
		actx = 3; 
	}else{
		actx = x%3;
	}

	if(y%3 == 0){
		acty = 3;
	}else{
		acty = y%3;
	}

	bool avlb = false;
	for(int i=1 ; i<=3 ; i++){
		for(int j=1 ; j<=3 ; j++){
			if(board[3*(actx-1)+i][3*(acty-1)+j] == '.'){
				avlb = true;
				break;
			}
		}
		if(avlb){
			break;
		}
	}

	for(int i=1 ; i<=3 ; i++){
		for(int j=1 ; j<=3 ; j++){
			if(board[3*(actx-1)+i][3*(acty-1)+j] == '.'){
				board[3*(actx-1)+i][3*(acty-1)+j] = '!'; 
			}
		}
	}

	if(!avlb){
		for(int i=1 ; i<=9 ; i++){
			for(int j=1 ; j<=9 ; j++){
				if(board[i][j] == '.'){
					board[i][j] = '!';
				}
			}
		}
	}
	for(int i=1 ; i<=9 ; i++){
		if(i%3 == 1 and i!=1){
			cout<<endl;
		}
		for(int j=1 ; j<=9 ; j++){
			cout<<board[i][j];
			if(j%3 == 0){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}