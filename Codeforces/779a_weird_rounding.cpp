#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
 
int main(){
	int k;
	string num;
	cin>>num>>k;
	int count=0;
	int no_of_consecutive_zeroes=0;
	int len;
	len = num.length();
	if(len<=k){
		count=len-1;
	}
	else{
		for(int i=0;i<len;i++){
			if(num[len-i-1]!='0'){
				count++;
			}
			else{
				no_of_consecutive_zeroes++;
			}

			if(no_of_consecutive_zeroes==k){
				break;
			}
		}
		if(no_of_consecutive_zeroes<k){
			count = len-1;
		}		
	}

	cout<<count<<endl;

	return 0;
}
