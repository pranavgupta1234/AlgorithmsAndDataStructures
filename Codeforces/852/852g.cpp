#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
	
	int n,m;
	cin>>n>>m;

	vector<string> words;
	vector<string> pattern; 

	for(int i=0 ; i<n ; i++){
		string t;
		cin>>t;
		words.push_back(t);
	}

	for(int i=0 ; i<m ; i++){
		string t;
		cin>>t;
		pattern.push_back(t);
	}

	for(int i=0 ; i<m ; i++){

		string pat = pattern[i];
		int count = 0;
		int ans = 0;
		vector<string> parts; 
		char* c;
		bool flag = true;
		
		for(int i=0 ; i<pat.length() ; i++){
			if(pat[i] == '?'){
				count++;
			}
		}		

		c = strtok(const_cast<char*>(pattern[i].c_str()),"?");

		//c_str() return pointer to c type char array
		while(c != NULL){
			parts.push_back(string(c));
			c = strtok(NULL,"?");
		}

		for(int i=0 ; i<words.size() ; i++){

			const char* seq = strstr(const_cast<char*>(words[i].c_str()),const_cast<char*>(parts[i].c_str()));

			for(int j=1 ; j<parts.size() ; j++){

				string par = parts[j];
				const char* temp = strstr(const_cast<char*>(words[i].c_str()),const_cast<char*>(par.c_str()));
				cout<<seq<<" "<<temp<<endl;
				if(temp < seq){
					flag = false;
				}else{
					seq = temp;
				}

				if(flag){
					ans++;
				}
			}
		}

		cout<<ans<<endl;
	}


	return 0;
}