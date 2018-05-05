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
	if(k == 1)	cout<<n<<endl, exit(0);
	else cout<<(ll)pow(2,floor(log2(n)+1))-1<<endl;
	return 0;
}