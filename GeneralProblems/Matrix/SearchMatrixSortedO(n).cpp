#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int mat[n][m];
		memset(mat,0,n*m);
		bool flag = false;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin>>mat[i][j];
			}
		}
		int element;
		cin>>element;
		int i = 0;
		int j = m-1;
		while(i <= n and j >= 0){

			if(mat[i][j] == element){
				flag = true;
				break;
			}else if(mat[i][j] > element){
				j--;
			}else{
				i++;
			}
		}
		cout<<(flag ? "1" : "0")<<endl;
	}
	return 0;
}