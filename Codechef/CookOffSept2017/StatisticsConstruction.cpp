#include <iostream>
#include <vector>

#define lar 1000000000

using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){

		bool flag = false;
		int n;
		cin>>n;

		if(n & 1){
			if(n + (n-1)/2 > lar){
				cout<<"-1";
				flag = true;
			}
			for(int i = n - (n-1)/2 ; i <= n + (n-1)/2 ; i++){
				if(flag){
					break;
				}
				cout<<i<<" ";
			}
		}else{
			if(n + n/2 > lar){
				cout<<"-1";
				flag = true;
			}
			for(int i = n - n/2 ; i < n + n/2 ; i++){
				if(flag){
					break;
				}
				cout<<i<<" ";
			}
		}

		cout<<endl;

	}

	return 0;
}