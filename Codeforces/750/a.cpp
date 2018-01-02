#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int i=1;
	for(; i<=n ; i++){
		if(5*i*(i+1)/2 + k > 240){
			break;
		}
	}

	cout<<i-1<<endl;

	return 0;
}