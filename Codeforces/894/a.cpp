#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
	string str;
	cin>>str;
	int total = 0;
	for(int i=0 ; i<str.length() ; i++){
		if(str[i] == 'Q'){
			for(int j=i+1 ; j<str.length() ; j++){
				if(str[j] == 'A'){
					for(int k=j+1 ; k<str.length() ; k++){
						if(str[k] == 'Q'){
							total++;
						}
					}
				}
			}
		}	
	}
	cout<<total<<endl;
	return 0;
}