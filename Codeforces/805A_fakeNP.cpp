#include <iostream>

using namespace std;

int main(){	

	int a,b;
	cin>>a>>b;

	int ans = 0; 

	if(b==a){
		if(a%2 == 0) {
			ans = 2;
		}else {
			ans = a;
		}
	}else{
		ans = 2;
	}



/*	for(int i=2 ; i<=max_divisor ; i++){

		offset = i - a%i;
		if(offset < b-a+1){
			if(abs(((b-(a+offset))+1)/i) > max_repeat){
				ans = i;
				max_repeat = ((b-(a+offset))+1)/i;	
			}			
		}else{
			if(a%i == 0){
				if(max_repeat < 1){
					ans = i;
					max_repeat = 1;
				}
			}
		}
	}*/

	cout<<ans<<endl;

	return 0;
}
