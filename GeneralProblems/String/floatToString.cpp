#include <iostream>
#include <math.h>

using namespace std;

bool is_integer(double x){
	return x - (long long int)x == 0;
}

int main(){
	
	double a = 23.563636678;
	char* string;
	int pos = 0;
	int count = 0;
	long long int num; 
	
	while(!is_integer(a)){
		pos++;
		a = a*10;
	}

	num = (long long int)a;

	long long int copy = num;

	while(copy){
		count++;
		copy /= 10;
	}

	cout<<num<<endl;

	char arr[count+2];

	arr[count+1] = '\0';

	for(int i = count ; i>=0 ; i--){
		if(i == count - pos){
			arr[i] = '.';
		}else{
			arr[i] = '0' + num % 10;
			num = num/10;
		}
	}

	cout<<arr<<endl;

	return 0;
}