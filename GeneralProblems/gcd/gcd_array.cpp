#include <iostream>
#include <vector>

using namespace std;

int gcd_arr(vector<int>&);
int gcd(int,int);

int main(){
	
	vector<int> a = { 11 , 33 , 55 , 22 , 121};
	cout<<gcd_arr(a)<<endl;

	return 0;
}

int gcd_arr(vector<int>& a){

	int res = a[0];

	for(int i=1 ; i<a.size() ; i++){
		res = gcd(a[i],res);
	}

	return res;
}

int gcd(int a,int b){
	if(a==0){
		return b;
	}else{
		return gcd(b%a,a);
	}
}