#include <iostream>
#include <cstring>
using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){

		int hash[2];
		hash[0]=0;
		hash[1]=0;
		string order;
		cin>>order;
		int x,y;
		cin>>x>>y;

		for(int i=0 ; i<order.length() ; i++){
			hash[order[i]-'a']++;
		}

		int a = hash[0]/x;
		int b = hash[1]/y;

		int min_ofab = min(a,b);

		for(int i=0 ; i < min_ofab ; i++){
			for(int i=0 ; i<x ; i++){
				cout<<"a";
			}
			for(int i=0 ; i<y ; i++){
				cout<<"b";
			}
			hash[0] -= x;
			hash[1] -= y;
			a--;
			b--;
		}

		if(b == 0){
			int newpair = hash[0]/hash[1];
			
			for(int i=0 ; i<newpair ; i++){
				cout<<"a";
			}

		}

		int a = hash[0]/x;
		int b = hash[1]/y;

		int rema = hash[0]%x;
		int remb = hash[1]%y;

		if(x > y){

		}else{

		}

		while(hash[0] and hash[1]){
			for(int i=0 ; i<x ; i++){

			}
		}



	}

	return 0;
}