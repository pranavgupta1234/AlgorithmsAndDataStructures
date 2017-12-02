#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int count=0;
		string s1 = bitset<11>(a).to_string();
		string s2 = bitset<11>(b).to_string();

		for(int i=0 ; i<s1.length() ; i++){
			if(s1[i] != s2[i]){
				count++;
			}
		}
		cout<<count<<endl;
	}

	return 0;
}