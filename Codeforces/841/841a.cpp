#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	
	int balloon;
	int friends;
	cin>>balloon>>friends;

	string colors;
	map<char,int> freq;


	cin>>colors;

	for(int i=0 ; i<colors.length() ; i++){
		freq[colors[i]]++;
	}

	for(map<char,int> :: iterator it=freq.begin() ; it != freq.end() ; it++){
		if(it -> second > friends){
			cout<<"NO"<<endl;
			exit(0);
		}
	}

	cout<<"YES"<<endl;


	return 0;
}