#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int n,k;
	cin>>n>>k;

	int min,max;

	if(k==0 or k==n){
		min = 0;
		max = 0;
	}else{
		min = 1;
		if(n&1){
			
			if(k == n/2){
				max = k+1;
			}else if(k == n/2 + 1){
				max = k - 1;
			}else if(k <= n/3){
				max = 2*k;
			}else{
				max = n - k;
			}

		}else{

			if(k==n/2){
				max = k;
			}
			else if( k <= n/3){
				max = 2*k;
			}else{
				max = n-k;
			}

		}
	}

	cout<<min<<" "<<max<<endl;

	return 0;
}