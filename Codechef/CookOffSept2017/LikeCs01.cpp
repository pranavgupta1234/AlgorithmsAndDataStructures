#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

#define hashChar 256

using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){

		bool flag = false;

		int freq[hashChar];
		
		for(int i=0 ; i<hashChar ; i++){
			freq[i] = 0;			
		}

		string str;
		cin>>str;

		for(int i=0 ; i<str.length() ; i++){
			freq[str[i]]++;
			if(freq[str[i]] > 1){
				flag = true;
				break;
			}
		}

		cout<<(flag ? "yes" : "no")<<endl;

	}


	return 0;
}