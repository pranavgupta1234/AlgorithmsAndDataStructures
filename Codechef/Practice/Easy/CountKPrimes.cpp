#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	
	int t;
	cin>>t;

	int status[100002];

	for(int i=0 ; i<100002 ; i++){
		status[i] = 0;
	}

	for(int k=1 ; k<100002 ; k++){

		map<int,int> hash;

		int i = k;

		while(i%2 == 0){
			hash[2]++;
			i/=2;
		}


		for(int j=3 ; j*j <= i ; j+=2){

			while(i%j == 0){

				hash[j]++;
				i /= j;

			}
		}

		if(i > 2){	
			hash[i]++;
		}

		status[k] = hash.size();
		
	}

	while(t--){

		int a,b,c;
		cin>>a>>b>>c;

		int count = 0;

		for(int i=a ; i<=b ; i++){
			if(status[i] == c){
				count++;
			}
		}

		cout<<count<<endl;
	}

	return 0;
}