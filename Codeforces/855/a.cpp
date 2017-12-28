#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	set<string> names;
	for(int i=0 ; i<n ; i++){
		string str;
		cin>>str;
		if(names.find(str) == names.end()){
			cout<<"NO"<<endl;
			names.insert(str);
		}else{
			cout<<"YES"<<endl;
		}
	}

	return 0;
}