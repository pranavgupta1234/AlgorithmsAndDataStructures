#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(){
	
	string first;
	string second;
	stack<char> common;

	cin>>first;
	cin>>second;


	int len1 = first.length();
	int len2 = second.length();

	int dpmat[len1+1][len2+1];

	for(int i=0 ; i<=len1 ; i++){
		dpmat[i][0] = 0;
	}

	for(int i=0 ; i<=len2 ; i++){
		dpmat[0][i] = 0;
	}

	for(int i=1 ; i<=len1 ; i++){
		for(int j=1 ; j<=len2 ; j++){
			if(first[i-1] == second[j-1]){
				dpmat[i][j] = 1 + dpmat[i-1][j-1];
			}else{
				dpmat[i][j] = max(dpmat[i-1][j],dpmat[i][j-1]);
			}
		}
	}

	for(int i=0 ; i<=len1 ; i++){
		for(int j=0 ; j<=len2 ; j++){
			cout<<dpmat[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<dpmat[len1][len2]<<endl;

	int i = len1;
	int j = len2;

	while(i>=0 and j>=0){
		
		if(first[i-1] == second[j-1]){
			common.push(first[i-1]);
			i--;
			j--;
		}else if(dpmat[i-1][j] > dpmat[i][j-1]){
			i--;
		}else{
			j--;
		}
	}

	while(!common.empty()){
		cout<<common.top()<<" ";
		common.pop();
	}

	cout<<endl;

	return 0;
}