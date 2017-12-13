#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int eval(int i,int j){
	int sum = i+j;
	string num = to_string(sum);
	int oddsum = 0;
	int evensum = 0;
	for(i=0 ; i<num.size() ; i++){
		if(num[i] & 1){
			oddsum += num[i] - '0';
		}else{
			evensum += num[i] -  '0';
		}
	}
	return abs(oddsum-evensum);
}

int main(){
	for(int val = 1 ; val < 25 ; val++){
		int mat[val][val];
		int sum1=0,sum2=0;
		for(int i=0 ; i<val ; i++){
			for(int j=0 ; j<val ; j++){
				cout<<i+j+2<<" ";
				sum1 += i+j+2;
			}
			cout<<endl;
		}
		cout<<endl;
		for(int i=0 ; i<val ; i++){
			for(int j=0 ; j<val ; j++){
				cout<<eval(i+1,j+1)<<" ";
				sum2 += eval(i+1,j+1);
			}	
			cout<<endl;
		}
		cout<<sum1<<" "<<sum2<<" ";
		cout<<sum1 - sum2<<endl;
		cout<<endl;
	}
	return 0;
}