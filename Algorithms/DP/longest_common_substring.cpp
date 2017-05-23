#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string LCS(string,string);

int main(){
	
	string str1;
	string str2;

	cout<<"Enter the two strings"<<endl;
	cin>>str1>>str2;

	cout<<LCS(str1,str2)<<endl;

	return 0;
}

string LCS(string str1,string str2){


	int m = 0,p,q;
	int arr[str1.length()+1][str2.length()+1];
	string result;

	memset(arr,0,(str1.length()+1)*(str2.length()+1)*sizeof(int));

	for(int i=1 ; i <= str1.length() ; i++){
		for(int j=1 ; j <= str2.length() ; j++){
			
			if(str1[i-1] == str2[j-1]){
				arr[i][j] = arr[i-1][j-1]+1;
				if(arr[i][j] > m){
					m = arr[i][j];
					p=i;
					q=j;
				}
			}
		}
	}
	if(m==0){
		return "No Match";
	}
	while(arr[p--][q--]){
		result.insert(result.begin(),str1[p]);
	}

	return result;
}