#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool myCompare(string X, string Y){

	string XY = X.append(Y);
	string YX = Y.append(X);

    // Now see which of the two formed numbers is greater
	return XY.compare(YX) > 0 ? true : false;
}

void printLargest(vector<string> arr){
	sort(arr.begin(), arr.end(), myCompare);
	for (int i=0; i < arr.size() ; i++ ){
		cout << arr[i];
	}
}

int main(){

	vector<string> arr;
	arr.push_back("999");
	arr.push_back("99978");
	printLargest(arr);
	return 0;
}