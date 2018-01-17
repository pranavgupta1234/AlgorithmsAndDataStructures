#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n,k;

bool is_integer(float a){
	return ceil(a) == a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	ll bits;
	ll ans = 0;
	if(is_integer(log2(n))){
		bits = log2(n) + 1; 
		if(k == 1) ans = n; 
		else 	ans = pow(2,bits)-1;
	}else{
		bits = ceil(log2(n));
		if(k == 1) ans = n;
		else ans = pow(2,bits)-1;

	}

	cout<<ans<<endl;


	return 0;
}