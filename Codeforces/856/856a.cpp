#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

#define MAX_SIZE 2000000
#define ll long long


using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){
		
		bool checkPossible[MAX_SIZE];
		memset(checkPossible,true,MAX_SIZE);

		int n;
		cin>>n;

		vector<int> setA(n,0);

		for(int i=0 ; i<n ; i++){
			cin>>setA[i];
		}

		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				for(int k=1 ; k<=1000000 ; k++){
					checkPossible[k + setA[i] - setA[j]] = false;
				}
			}
		}

		cout<<"YES"<<endl;
		int i=0;
		while(n){
			if(checkPossible[i] == true){
				cout<<i<<" ";
				n--;
			}
			i++;
		}

		cout<<endl;

	}
	
	return 0;
}