#include <iostream>
#include <string>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){
		
		string str;
		cin>>str;
		bool flag = true;

		if(str[0] == str[1]){
			flag = false;
		}else{
			for(int i=0 ; i+2 < str.size() ; i++){
				if(str[i] != str[i+2]){
					flag = false;
					break;
				}
			}
		}

		cout<<(flag ? "YES" : "NO")<<endl;

	}
	
	return 0;
}
