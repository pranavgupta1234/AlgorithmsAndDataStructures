#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

#define range 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	bool* isprime = new bool[range];
	memset(isprime,true,sizeof(isprime[0])*range);
	isprime[0] = false;
	isprime[1] = false;
	for(int i=2 ; i<=sqrt(range) ; i++){
		if(isprime[i]){
			for(int j = 2*i ; j<=range ; j+=i){	
				isprime[j] = false;
			}
		}
	}
	while(t--){
		int n,m;
		cin>>n>>m;	
		for(int i=n ; i<=m ; i++){
			if(isprime[i]){
				cout<<i<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}