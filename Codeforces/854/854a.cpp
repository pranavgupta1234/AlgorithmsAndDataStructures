#include <iostream>
#include <vector>

using namespace std;

int gcd(int,int);

int main(){
	
	int n;
	cin>>n;

	int i,j;

	if(n&1){
		i=n/2;
		j=n/2+1;	
	}else{
		i=n/2-1;
		j=n/2+1;
	}

	while(i>=1 and j<=n){
		if(gcd(i,j) == 1){
			cout<<i<<" "<<j;
			break;
		}else{	
			i--;
			j++;
		}
	}
	
	cout<<endl;

	return 0;
}

int gcd(int a,int b){

	if(a==0){
		return b;
	}else{
		return gcd(b%a,a);
	}
}