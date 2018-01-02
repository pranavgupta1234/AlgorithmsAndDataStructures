#include <bits/stdc++.h>

using namespace std;

bool is_integer(float a){
	return ceil(a) == a;
}

int gcd(int a,int b){
	if(a==0) return b; 
	else return gcd(b%a,a);
}

int main(){
	ios_base::sync_with_stdio(false);
	int a,b;
	cin>>a>>b;
	int x1,y1,x2,y2;
	bool flag = false;
	for(int i=1 ; i<a ; i++){
		if(is_integer(sqrt(a*a-i*i))){
			x1 = i;
			y1 = sqrt(a*a-i*i);
			flag = true;
			break;
		}
	}

	if(flag){
		x2 = -y1/gcd(x1,y1);
		y2 = x1/gcd(x1,y1);
		int expb = sqrt(x2*x2 + y2*y2);

		if(b % expb == 0){	
			flag = true;
			x2 *= b/expb;
			y2 *= b/expb;
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}

		if(x1 == x2 or y1 == y2){
			swap(x1,y1);
			swap(x2,y2);
			x2 *= -1;
			y2 *= -1;
		}

	}

	
	if(flag){
		cout<<"0 0"<<endl;
		cout<<x1<<" "<<y1<<endl;
		cout<<x2<<" "<<y2<<endl;
	}
}