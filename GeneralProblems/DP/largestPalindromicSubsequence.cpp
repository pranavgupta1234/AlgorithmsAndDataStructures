#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int largestPalindSub(string& str){
	int len = str.length();
	int dpmat[len][len];
	memset(dpmat,0,sizeof(dpmat[0][0])*len*len);
	for(int i=0 ; i<len ; i++){
		dpmat[i][i] = 1;
	}
	for(int l=2 ; l<=len ; l++){
		for(int i=0 ; i<len-l+1; i++){
			int j=i+l-1;
			if(str[i] == str[j]){
				dpmat[i][j] = 2 + dpmat[i+1][j-1];
			}else{
				int maxval = -1;
				dpmat[i][j] = max(maxval,max(dpmat[i][j-1],dpmat[i+1][j]));
			}

		}
	}
	return dpmat[0][len-1];
}

int main(){
	
	string str;
	cin>>str;

	cout<<largestPalindSub(str);

	return 0;
}