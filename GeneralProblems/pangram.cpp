#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){

		map<char,int> hash;

		vector<int> prices;
		string text;
		long long int sum = 0;

		for(int i=0 ; i<26 ; i++){
			int p;
			cin>>p;
			prices.push_back(p);
		}

		cin>>text;

		for(int i=0 ; i<26 ; i++){
			hash['a'+i] = 0;
		}

		for(int i=0 ; i<text.length() ; i++){
			hash[text[i]]++; 
		}

		for(int i=0 ; i<26 ; i++){

			if(hash['a'+i] == 0){
				sum  =  sum + prices[i];
			}

		}

		cout<<sum<<endl;

	}


	return 0;
}