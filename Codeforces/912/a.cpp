#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a,b,x,y,z;
	cin>>a>>b>>x>>y>>z;
	ll total = 0;
	if(2*x + y >= a){
		total += (2*x+y) - a;
	}

	if(y + 3*z >= b){
		total +=  (y+3*z) - b;
	}

	cout<<total<<endl;

	return 0;
}