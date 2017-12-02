#include <iostream>
#include <queue>
#include <string>

using namespace std;

//here each 
int main(){
	
	int n;
	cin>>n;

	queue<string> q;
	q.push("1");

	while(n--){

		string s = q.front();
		q.pop();

		cout<<s<<" ";

		string s2 = s;
		q.push(s2.append("0"));

		q.push(s.append("1"));
	}

	cout<<endl;
	
	return 0;
}