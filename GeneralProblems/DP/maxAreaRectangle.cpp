#include <iostream>
#include <vector>

#define rows 4
#define cols 6

#define INT_MAX 1000000000

using namespace std;

int findAreaHistogram(int* row,int c){

	int max_area = 0;
	int mini = INT_MAX;
	int count=0;
	int area = 0;

	for(int i=0 ; i<c ; i++){
		
		if(row[i] != 0 or i == c-1){
			count++;			
			mini = min(mini,row[i]);
		}

		max_area = max(max_area,count*mini);

	}

	return max_area;
}

int main(){
	
	int maxarea = 0;

	int rect[rows][cols] = {
		{ 1 , 0 , 0 , 1 , 1 , 1},
		{ 1 , 0 , 1 , 1 , 0 , 1},
		{ 0 , 1 , 1 , 1 , 1 , 1},
		{ 0 , 0 , 1 , 1 , 1 , 1},
	};

	int* row = new int[cols];

	//memset(row,0,cols);

	for(int i=0 ; i<cols ; i++){
		row[i] = 0;
	}
	
	int j=0;

	while(j < rows){
		
		for(int i=0 ; i<cols ; i++){
			if(rect[j][i] == 0){
				row[i] = 0;
			}else{
				row[i] += rect[j][i];
			}
		}

/*		for(int i=0 ; i<cols ; i++){
			cout<<row[i]<<" ";
		}

		cout<<endl;

		cout<<findAreaHistogram(row,cols)<<endl;
*/
		maxarea = max(maxarea,findAreaHistogram(row,cols));

		j++;
	}

	cout<<maxarea<<endl;

	delete[](row);

	return 0;
}