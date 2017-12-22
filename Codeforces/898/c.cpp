#include <bits/stdc++.h>
#include <cstring>

using namespace std;

struct record{
	string name;
	int no;
	vector<string> nums;  
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin>>m;
	unordered_map<string,set<string> > phonebook;
	for(int i=0 ; i<m ; i++){
		string name;
		int no;
		vector<string> phno;
		cin>>name;
		cin>>no;
		for(int j=0 ; j<no ; j++){
			string number;
			cin>>number;
			phonebook[name].insert(number);
		}
	}
	for(auto it = phonebook.begin() ; it != phonebook.end() ; it++){
		string name = it -> first;
		for(auto itr = phonebook[name].begin() ; itr != phonebook[name].end() ; itr++){
			string str = *itr;
			string revstr = str;
			reverse(revstr.begin(),revstr.end());
			while(revstr.length() != 0){
				revstr.pop_back();
				reverse(revstr.begin(),revstr.end());
				if(phonebook[name].find(revstr) != phonebook[name].end()){
					phonebook[name].erase(revstr);
				}
				reverse(revstr.begin(),revstr.end());
			}
		}
	}
	cout<<phonebook.size()<<endl;
	for(auto it = phonebook.begin() ; it != phonebook.end() ; it++){
		string name = it -> first;
		set<string> phnos = it -> second;
		cout<<name<<" "<<phnos.size()<<" ";
		for(auto i=phnos.begin() ; i != phnos.end() ; i++){
			cout<<*i<<" ";
		}
		cout<<endl;
	}

	return 0;
}