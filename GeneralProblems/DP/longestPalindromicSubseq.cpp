#include <iostream>
#include <string>

using namespace std;

int lengthOfLPSubsequence(string& str);

int main(){
	
	string str;
	cin>>str;

	cout<<lengthOfLPSubsequence(str);

	cout<<endl;

	return 0;
}

int lengthOfLPSubsequence(string& str){

	int size = str.length();

	int dpMat[size][size];

	int i,j;

	for(int i=0 ; i<size ; i++){
		for(int j=0 ; j<size ; j++){
			if(i==j){
				dpMat[i][j] = 1;				
			}else{
				dpMat[i][j] = 0;
			}
		}
	}
	for(int l=2 ; l<=size ; l++){
		i=0;
		j=l-1;
		while(i<size and j<size){
			if(str[i] == str[j]){
				dpMat[i][j] = 2 + dpMat[i+1][j-1];
			}else{
				dpMat[i][j] = max(dpMat[i+1][j],dpMat[i][j-1]);
			}

			i++;
			j++;
		}
	}

/*	for(int i=0 ; i<size ; i++){
		for(int j=0 ; j<size ; j++){
			cout<<dpMat[i][j]<<" ";
		}
		cout<<endl;
	}*/

	return dpMat[0][size-1];
}