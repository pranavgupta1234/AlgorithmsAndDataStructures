#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){

	string str;
	cin>>str;
	int arr[26];

	unordered_map<char,int> hash;

	for(int i=0 ; i<26 ; i++){
		arr[i]=0;
	}

	for(int i=0 ; i<str.length() ; i++){
		arr[str[i]-'a']++;
	}

	int t;
	cin>>t;

	while(t--){

		bool flag = true;

		string test;
		cin>>test;

		for(int i=0 ; i<test.length() ; i++){
			if(arr[test[i]-'a'] == 0){
				flag = false;
				break;
			}
		}

		cout<<(flag ? "Yes" : "No")<<endl;
	}


	return 0;
}