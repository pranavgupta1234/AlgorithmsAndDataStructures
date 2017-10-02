#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	
	int t;
	cin>>t;
	
	while(t--){
		bool flag = true;
		
		string str;
		cin>>str;	

		set<char> allowed;
		
		allowed.insert('C');
		allowed.insert('E');
		allowed.insert('S');


		if(str.size() == 1){
			flag = true;
			break;
		}else if(str.size() == 2){
			if(str == "CC" or str == "EE" or str == "SS" or str == "CE" or str == "CS" or str == "ES"){
				flag = true;
				break;
			}else{
				flag = false;
				break;
			}
		}else{

			for(int i =0 ; i<str.size() ; i++){

				if(allowed.find(str[i]) != allowed.end()){
					if(str[i] == 'E'){
						allowed.erase('C');
					}else if(str[i] == 'S'){
						allowed.erase('C');
						allowed.erase('E');
					}
					continue;
				}else{
					flag = false;
					break;
				} 
			}	
		}
		
		cout<<(flag ? "yes" : "no")<<endl;
		allowed.clear();
		str.clear();
	}
	
	
	return 0;
}