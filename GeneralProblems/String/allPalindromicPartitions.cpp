#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string str,int low,int high){
	while(low < high){
		if(str[low] != str[high]){
			return false;
		}
		low++;
		high--;
	}
	return true;
}

void allPalPartitionsUtil(vector<vector<string> >& allPar,vector<string>& currPar,int start,int n,string str){
	if(start >= n){
		allPar.push_back(currPar);
		return ;
	}
	for(int i=start ; i<n ; i++){
		if(isPalindrome(str,start,i)){
			currPar.push_back(str.substr(start,i-start+1));
			allPalPartitionsUtil(allPar,currPar,i+1,n,str);
			currPar.pop_back();
		}
	}
}

void allPalPartitions(string str){
	int n = str.length();
	vector< vector<string> > allPar;
	vector<string> currPar;
	allPalPartitionsUtil(allPar,currPar,0,n,str);
	for(int i=0 ; i<allPar.size() ; i++){
		for(int j=0 ; j<allPar[i].size() ; j++){
			cout<<allPar[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	string str;
	cin>>str;
	allPalPartitions(str);
	return 0;
}