#include <iostream>
#include <cmath>

using namespace std;

//gives soln to eqn -> ax + by = gcd(a,b) as a and b are given and x and y are integers 
int gcd(int a,int b,int& x,int& y){
	if(a == 0){
		x = 0;
		y = 1;
		return b;
	}

	int x1,y1;
	int d = gcd(b%a,a,x1,y1);
	y = x1;
	x = y1 - (b/a)*x1;
	return d;
}

bool anySoln(int a,int b,int c,int& x,int& y,int& g){	
	g = gcd(abs(a),abs(b),x,y);
	if(c % g != 0){
		return false;
	}else{
		x = x*(c/g);
		y = y*(c/g);
		if(a<0) 	{ x = x*(-1); } 
		if(b<0)		{ y = y*(-1); }
		return true;	
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int a,b,c;
	cin>>a>>b>>c;
	int x=1,y=1,g=0;
	if(anySoln(a,b,c,x,y,g)){
		cout<<anySoln(a,b,c,x,y,g)<<endl;
		cout<<x<<" "<<y<<endl;
	}else{
		cout<<"No Solution ! "<<endl;
	}
	return 0;
}