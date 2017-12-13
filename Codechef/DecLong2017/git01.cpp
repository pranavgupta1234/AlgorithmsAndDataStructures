#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		char mat[n][m];
		char type1[n][m];
		char type2[n][m];
		bool flag = true;
		for(int i=0 ; i<m ; i++){
			if(flag){
				type1[0][i] = 'R';
				type2[0][i] = 'G';
				flag = false;
			}else{
				type1[0][i] = 'G';
				type2[0][i] = 'R';
				flag = true;
			}
		}
		for(int i=1 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(type1[i-1][j] == 'R'){
					type1[i][j] = 'G';
				}else{
					type1[i][j] = 'R';
				}	
			}
		}
		for(int i=1 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(type2[i-1][j] == 'R'){
					type2[i][j] = 'G';
				}else{
					type2[i][j] = 'R';
				}	
			}
		}
		memset(mat,0,sizeof(mat[0][0])*n*m);
		int cost1 = 0,cost2 = 0;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin>>mat[i][j];
			}
		}
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(mat[i][j] - type1[i][j] > 0){
					cost1 += 5;
				}else if(mat[i][j] - type1[i][j] < 0){
					cost1 += 3;
				}		
			}
		}
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(mat[i][j] - type2[i][j] > 0){
					cost2 += 5;
				}else if(mat[i][j] - type2[i][j] < 0){ 
					cost2 += 3;
				}		
			}
		}
		cout<<min(cost1,cost2)<<endl;
	}
}