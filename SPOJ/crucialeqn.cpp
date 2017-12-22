#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long

using namespace std;

ll gcd(ll a,ll b){
	return (a == 0 ? b : gcd(b%a,a));
}

int main(){
	ll t;
	cin>>t;
	ll j = 1;
	while(j <= t){
		ll a,b,c;
		cin>>a>>b>>c;
		cout<<"Case "<<j<<": ";
		if(!(c%gcd(a,b))){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
		j++;
	}
	return 0;
}