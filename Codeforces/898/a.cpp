#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
	ll n;
	cin>>n;
	cout<<(n/10)*10 + (n%10 < 5 ? 0 : 10)<<endl;
	return 0;
}