#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a,b;

int main(){
	cin>>a>>b;
	if(floor(sqrt(a)) > floor((sqrt(1+4*b)-1)/2))		cout<<"Valera"<<endl;
	else cout<<"Vladik"<<endl;
	return 0;
}
