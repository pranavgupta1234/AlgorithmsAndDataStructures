#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll n,b;
ll x_intcpt,y_intcpt;
ll m = 0;

bool is_int(float a){
	return ceil(a) == a;
}

int main(){	

	cin>>n>>b;
	x_intcpt = n*b;
	y_intcpt = b;	
	for(ll i = y_intcpt ; i>=0 ; i--){
		ll j = (b-i)*n;
		ll val = 0;
		ll temp = ((i+1)*i)/2;
		val += (j+1)*temp;
		val += ((i+1)*(j+1)*j)/2;	 
		m = max(m,val);

	}	
	cout<<m<<endl;

	return 0;
}