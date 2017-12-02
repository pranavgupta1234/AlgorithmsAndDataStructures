#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		int start = 2*1000000000; 
		int nd = n;
		for(int i=0 ; i<n ; i++){
			cout<<start-nd<<" ";
			nd--;
		}

		cout<<endl;

	}


	return 0;
}