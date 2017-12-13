#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
	string str;
	cin>>str;
	int total = 0;
	int totalQ = 0;
	int prefixSumQ[100];
	memset(prefixSumQ,0,sizeof(prefixSumQ[0])*100);
	for(int i=0 ; i<str.length() ; i++){
		if(str[i] == 'Q'){
			totalQ++;
		}
	}
	for(int i=0 ; i<str.length() ; i++){
		if(str[i] == 'Q'){
			total++;
		}
		if(str[i] == 'A'){
			prefixSumQ[i] = total;	
		}
	}
	total = 0;
	for(int i=0 ; i<str.length() ; i++){
		if(str[i] == 'A'){
			if(prefixSumQ[i] != 0 or prefixSumQ[i] != str.length()-1){
				total += max(prefixSumQ[i],totalQ - prefixSumQ[i]);
			}
		}
	}

	cout<<total<<endl;
	return 0;
}