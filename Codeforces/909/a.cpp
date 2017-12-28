#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string front;
	string back;
	cin>>front>>back;
	string back_cpy = back;
	vector<string> poss;
	while(!front.empty()){
		back = back_cpy;
		while(!back.empty()){
			string str = front + back;
			poss.push_back(str);
			back.pop_back();
		}
		front.pop_back();
	}

	sort(poss.begin(),poss.end());

	cout<<*poss.begin()<<endl;

	return 0;
}