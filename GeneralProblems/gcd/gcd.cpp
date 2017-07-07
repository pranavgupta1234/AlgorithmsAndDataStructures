#include <iostream>

using namespace std;

int gcd_sub(int,int);
int gcd_mod(int,int);

/*Time Complexity: O(Log min(a, b))*/

/*Also Remember :: The least common multiple (lcm) of a and b is their product divided by their
 greatest common divisor (gcd) ( i.e. lcm(a, b) = ab/gcd(a,b)).*/

int main(){	
	
	int a,b;
	cin>>a>>b;
	cout<<gcd_mod(a,b)<<endl;

	return 0;
}

int gcd_sub(int a,int b){

	if(a==0 or b==0){
		return 0;
	}

	if(a==b){
		return a;
	}

	if(a>b){
		return gcd_sub(a-b,b);
	}else{
		return gcd_sub(a,b-a);
	}

}

int gcd_mod(int a,int b){

	if(a==0){
		return b;
	}else{
		return gcd_mod(b%a,a);
	}
}