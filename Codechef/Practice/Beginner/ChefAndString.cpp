#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string str;
	cin>>str;

	int c=0,ch=0,che=0,chef=0;

	for(int i=0 ; i<str.size() ; i++){
		if(str[i]=='C'){
			c++;
		}else if(str[i] == 'H'){
			if(c>0){
				c--;
				ch++;
			}
		}else if(str[i] == 'E'){
			if(ch>0){
				ch--;
				che++;
			}
		}else if(str[i] == 'F'){
			if(che > 0){
				che--;
				chef++;
			}
		}
	}

	cout<<chef<<endl;

	return 0;
}