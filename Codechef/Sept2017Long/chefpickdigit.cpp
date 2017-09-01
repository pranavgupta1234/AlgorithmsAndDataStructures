#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){

		string num;
		cin>>num;
		map<char,int> frequency;
		set<char> output;
		set<char> :: iterator it;
		stringstream ss;
		string temp_str;

		for(int i=0 ; i<10 ; i++){
			frequency['0'+i] = 0;
		}

		for(int i=0 ; i<num.length() ; i++){
			frequency[num[i]]++;
		}

/*		for(int i=48 ; i<=57 ; i++){
			cout<<i<<" "<<frequency[i]<<" ";
		}			

		cout<<endl;*/

		for(int i=65 ; i<=90 ; i++){
			ss.str(string());
			ss<<i;
			temp_str = ss.str();
			//cout<<temp_str<<endl;
			if(temp_str[0] == temp_str[1]){
				if(frequency[temp_str[0]] >= 2){
					output.insert((char)i);
				}
			}
			else if(frequency[temp_str[0]] > 0 and frequency[temp_str[1]] > 0){
				output.insert((char)i);
			}
		}

		for(it = output.begin() ; it != output.end() ; it++){
			cout<<*it;
		}

		cout<<endl;
	}

	return 0;
}


