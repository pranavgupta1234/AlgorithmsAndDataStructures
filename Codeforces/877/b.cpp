#include <bits/stdc++.h>

using namespace std;

bool isbeautiful(deque<char>& s){
	bool isa;
	bool isb;

	for(int i=0 ; i<s.size() ; i++){
		if(s[i] == 'a'){
			isa = tr
		}	
	}
}

int main(){
	
	string str;
	cin>>str;
	deque<char> s;

	for(int i=0 ; i<str.size() ; i++){
		s.push_back(str[i]);
	}

	bool flag = false;
	while(isbeautiful(s)){
		flag ? s.pop_front() : s.pop_back(); 
	}

	cout<<s.size()<<endl;

	return 0;
}