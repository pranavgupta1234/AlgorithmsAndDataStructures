#include <iostream>
#include <vector>

using namespace std;

int fact(int);

int main(){
	
	int a,b;

	cin>>a>>b;

	cout<<fact(min(a,b))<<endl;

}


int fact(int a){

	int ans =1;

	for(int i=2 ; i<=a ; i++){
		ans = ans*i;
	}

	return ans;

}