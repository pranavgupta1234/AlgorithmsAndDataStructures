#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int n,k,t;
	cin>>n>>k>>t;

	if(t <= k){
		cout<<t<<endl;
	}else if(t > k and t <= n){
		cout<<k<<endl;
	}else{
		cout<<n+k-t<<endl;
	}

	return 0;
}