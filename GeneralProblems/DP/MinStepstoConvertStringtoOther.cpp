#include <iostream>
#include <vector>
#include <string>

using namespace std;

int MinSteps(string str1,string str2){

	int len1 = str1.length();
	int len2 = str2.length();

	int dpmat[len1+1][len2+1];

	for(int i=0 ; i<=len1 ; i++){
		dpmat[i][0] = i;
	}

	for(int i=0 ; i<=len2 ; i++){
		dpmat[0][i] = i;
	}

	for(int i=1 ; i<=len1 ; i++){
		for(int j=1 ; j<=len2 ; j++){
			if(str1[i-1] == str2[j-1]){
				dpmat[i][j] = dpmat[i-1][j-1];
			}else{
				dpmat[i][j] = 1 + min(dpmat[i-1][j-1],min(dpmat[i-1][j],dpmat[i][j-1]));
			}
		}
	}

	return dpmat[len1][len2];
}

int main(){
		
	string str1,str2;
	cin>>str1>>str2;

	cout<<MinSteps(str1,str2)<<endl;

	return 0;
}