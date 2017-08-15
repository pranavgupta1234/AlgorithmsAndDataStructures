#include <iostream>
#include <cmath>

using namespace std;

bool isMultipleOf3(int n){

	int odd_count=0;
	int even_count=0;

	if(n<0){
		n=-n;
	}
	if(n==0){
		return true;
	}
	if(n==1){
		return false;
	}

	while(n){

		if(n&1){
			odd_count++;
		}
		n = n>>1;

		if(n&1){
			even_count++;
		}

		n = n>>1;

	}

	return isMultipleOf3(abs(odd_count-even_count));


}

int main(){
	
	int no = 214;

	cout<<(isMultipleOf3(no) ? "Yes" : "No")<<endl;

	return 0;
}