#include <iostream>
#include <string>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){
		
		int n;
		cin>>n;

		int i=1;

		while(n--){
			cout<<i<<" ";
			i+=2;
		}

		cout<<endl;
		
	}
	
	return 0;
}