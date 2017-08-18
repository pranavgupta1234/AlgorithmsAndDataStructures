#include <iostream>
#include <string>

using namespace std;

void LongestCommonSubsequence(string str1,string str2){

	int DPmat[str2.length()+1][str1.length()+1];

	for(int i=0 ; i<=str1.length() ; i++){
		DPmat[0][i]=0;
	}

	for(int i=0 ; i<=str2.length() ; i++){
		DPmat[i][0]=0;
	}

	for(int i=1 ; i<str2.length()+1 ; i++){
		for(int j=1 ; j<str1.length()+1 ; j++){
			if(str2[i-1] == str1[j-1]){
				DPmat[i][j] = DPmat[i-1][j-1] + 1;
			}else{
				DPmat[i][j] = max(DPmat[i-1][j],DPmat[i][j-1]); 
			}
		}
	}

	for(int i=0 ; i<=str2.length() ; i++){
		for(int j=0 ; j<=str1.length() ; j++){
			cout<<DPmat[i][j]<<" ";
		}
		cout<<endl;
	}


	int size = DPmat[str2.length()][str1.length()];
	char arr[size+1];

	arr[size] = '\0';

	int i = str2.length();
	int j = str1.length();

	while(i > 0 and j > 0){

		if(str2[i-1] == str1[j-1]){
			arr[size-1] = str2[i-1];
			i--;
			j--;
			size--;
		}

		else if(DPmat[i-1][j] > DPmat[i][j-1]){
			i--;
		}else{
			j--;
		}
	}

	cout<<arr<<endl;
}

int main(){

	string str1 = "abcdaf";
	string str2 = "acbcf";


	LongestCommonSubsequence(str1,str2);

	return 0;
}

