#include <iostream>
#include <vector>

using namespace std;

bool is_integer(double x){

	if( x - (int)x == 0){
		return true;
	}

	return false;
	
}

int main(){
	
	long int num;
	cin>>num;

	long int n = 2;

	int total = 0;

	while((n*(n+1))/2 <= num){

		double a = (double)num/(double)n - (double)(n+1)/2;

		if(is_integer(a)){
			total++;
		}

		n++;

	}

	cout<<total<<endl;

	return 0;
}