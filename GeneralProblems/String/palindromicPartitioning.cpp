#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

bool isPalindrome(string& str,int low,int high){
	while(low < high){
		if(str[low] != str[high]){
			return false;
		}
		low++;
		high--;
	}
	return true;
}

int palindromicPartitions(string& str){
	
	int len = str.length();
	int dpmat[len][len];
	memset(dpmat,0,sizeof(dpmat[0][0])*len*len);
	for(int i=0 ; i<len ; i++){
		dpmat[i][i] = 0;
	}
	for(int l=2 ; l<=len ; l++){
		//starting index
		for(int i=0 ; i<len-l+1 ; i++){
			int j = i + l - 1;
			if(isPalindrome(str,i,j)){
				dpmat[i][j] = 0;
			}else{
				int minval = INT_MAX;
				for(int k=i ; k<j ; k++){
					minval = min(minval,dpmat[i][k] + dpmat[k+1][j]);
				}
				dpmat[i][j] = 1 + minval;
			}
		}
	}

	return dpmat[0][len-1];
}

int main(){
	
	string str;
	cin>>str;

	cout<<palindromicPartitions(str);

	return 0;
}