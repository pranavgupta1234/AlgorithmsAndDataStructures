#include <iostream>
#include <map>

using namespace std;

int main(){
	//doing hash[k]++ will start incrementing from zero (initilization with 0)
	map<int,int> factors;	
	int n;
	cin>>n;

	while(n%2 == 0){
		cout<<"2 ";
		factors[2]++; 
		n/=2;
	}

	for(int i=3 ; i*i <= n ; i++){
		while(n%i == 0){
			factors[i]++;
			cout<<i<<" ";
			n/=i;
		}
	}

	if(n > 2){
		cout<<n<<" ";
		factors[n]++;
	}

	cout<<endl;

	for(map<int,int> :: iterator it = factors.begin() ; it != factors.end() ; it++){
		cout<<it -> first <<" "<<it -> second<<endl;
	}

	return 0;
}