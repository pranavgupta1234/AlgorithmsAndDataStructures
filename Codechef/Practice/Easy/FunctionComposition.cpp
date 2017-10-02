#include <iostream>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

int main(){
	
	int n;
	cin>>n;

	unordered_map<string,string> hash1,hash2;
	stack<string> res;

	for(int i=0 ; i<n ; i++){
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		hash1[s2] = s1;
		hash2[s2] = s3;
	}

	string str;
	str = hash1["inp"];
	res.push(str);
	string s = hash2["inp"];

	for(int i=0 ; i<n-1 ; i++){
		res.push(hash1[s]);
		s = hash2[s];
	}

	while(!res.empty()){
		string t = res.top();
		res.pop();
		cout<<t;
		if(!res.empty()){
			cout<<".";			
		}
	}

	cout<<endl;
	

	return 0;
}