#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	
	string str;
	cin>>str;

	int len = str.length();
	int zero_count = 0;
	int one_count = 0;
	bool flag = false;
	for(int i=len-1 ; i>=0 ; i--){
		if(str[i] == '0'){
			zero_count++;
		}
		if(str[i] == '1'){
			one_count++;
		}
		if(zero_count >= 6 and one_count !=0){
			flag = true;
			break;
		}
	}

	cout<<(flag ? "yes" : "no")<<endl;

	return 0;
}