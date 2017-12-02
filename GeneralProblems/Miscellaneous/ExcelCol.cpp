#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main(){
	
	string str;
	int n;
	cin>>n;

	while(n > 0){

		if(n%26 == 0){
			str.push_back('Z');
			n = n/26 - 1;
		}else{
			int r = n%26;
			str.push_back(r-1 + 'A');
			n = n/26;
		}
	}

	for(int i=str.length()-1 ; i>=0 ; i--){
		cout<<str[i];
	}
	cout<<endl;
	return 0;
}