#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;

	while(n--){

		int rows;
		cin>>rows;

		int triangle[rows][rows];
		int sums[rows][rows];

		int max_ele = 0;

		for(int i=0 ; i<rows ; i++){
			for(int j=0 ; j<rows ; j++){
				triangle[i][j]=0;
				sums[i][j]=0;
			}
		}

		int i=1;

		while(i <= rows){
			for(int j=0 ; j < i ; j++){
				int temp;
				cin>>temp;
				triangle[i-1][j] = temp;
			}
			i++;
		}

/*		for(int i=0 ; i<rows ; i++){
			for(int j=0 ; j<rows ; j++){
				cout<<triangle[i][j]<<" ";
			}
			cout<<endl;
		}
*/
		for(int i=0 ; i<rows ; i++){
			for(int j=0 ; j<i+1 ; j++){
				int posval = triangle[i][j];
				int upper=0,upperLeft=0;
				i-1 >= 0 and j >= 0 ? upper = sums[i-1][j] : upper = 0;
				i-1 >= 0 and j-1 >= 0 ? upperLeft = sums[i-1][j-1] : upperLeft = 0;
				posval += max(upper,upperLeft);
				//cout<<i<<" "<<j<<" "<<posval<<" "<<upper<<" "<<upperLeft<<endl;	
				sums[i][j] = posval;
				if(i == rows-1){
					max_ele = max(max_ele,sums[i][j]);
				}	
			}
		}

/*		for(int i=0 ; i<rows ; i++){
			for(int j=0 ; j<rows ; j++){
				cout<<sums[i][j]<<" ";
			}
			cout<<endl;
		}*/

		cout<<max_ele<<endl;

	}


	return 0;
}