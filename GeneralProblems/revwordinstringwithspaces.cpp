#include <iostream>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){

		string sentence;
		fgets(const_cast<char*>(sentence.c_str()),200,stdin);
		stack<string> rev;

		char* token = strtok(const_cast<char*>(sentence.c_str())," ");

		while(token != NULL){
			string str(token);
			rev.push(str);
			token = strtok(NULL," ");
		}

		while(!rev.empty()){

			string s = rev.top();
			rev.pop();
			cout<<s;
		}

		cout<<endl;

	}

	return 0;
}