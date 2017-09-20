#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
using namespace std;

int main(){
	
	long long int n;
	ll int k;

	cin>>n;
	cin>>k;

	if(k > n*(n-1)/2){
		cout<<"IMPOSSIBLE"<<endl;
		exit(0);
	}

	long long int noNestedBracket = sqrt(2*k) + 1;
	
	long long int otherBracket = 2*n - noNestedBracket*2;

	for(int i=0 ; i<otherBracket/2 ; i++){
		cout<<"()";
	} 

	for(int i=0 ; i<noNestedBracket ; i++){
		cout<<"(";
	}

	for(int i=0 ; i<noNestedBracket ; i++){
		cout<<")";
	}

	cout<<endl;

	return 0;
}