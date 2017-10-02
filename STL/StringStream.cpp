#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
	
	int a = 23456;
	float fl = 2356.7766;
	double db = 348295.3523;

	string number = "33425.456";
	double d;

	stringstream ss;

	ss<<fl;
	string str1;
	str1 = ss.str(); 
	cout<<str1<<endl;

	cout<<str1[4]<<endl;

	stringstream strings;
	strings << number;
	strings>>d;

	cout<<d/2<<endl;

	return 0;
}