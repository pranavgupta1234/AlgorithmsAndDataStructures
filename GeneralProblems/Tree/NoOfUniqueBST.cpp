#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//this is also a program to generate catalan numbers
int main(){
	
	int t;
	cin>>t;
	while(t--){

		int n;
		cin>>n;

		int nos[n+1];

		for(int i=0 ; i<=n ; i++){
			nos[i] = 0;
		}

		nos[0] = nos[1] = 1;

		for(int i=2 ; i<=n ; i++){
			for(int j=1 ; j<=i ; j++){
				nos[i] += nos[j-1]*nos[i-j];
			}
		}

		cout<<nos[n]<<endl;

	}


	return 0;
}