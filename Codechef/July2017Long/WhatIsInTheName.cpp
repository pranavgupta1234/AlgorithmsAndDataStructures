#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int t;

	cin>>t;
	char name[50];

	while(t--){

		cin.ignore();	
		int spaces = 0;

		for(int i=0 ; i<50 ; i++){
			name[i] = '-';
		}

		cin.getline(name,sizeof(name));

		for(int i=0 ; i<50 ; i++){
			if(name[i] == ' '){
				spaces++;
			}
		}		

		int j;

		if(spaces == 0){
			
			j=0;

			while(name[j]!='-'){
				if(j==0){
					cout<<(char)toupper(name[0]);
				}else{
					cout<<(char)tolower(name[j]);
				}
				j++;
			}
			cout<<endl;

		}else if(spaces == 1){

			j=0;

			cout<<(char)toupper(name[0]);
			cout<<". ";

			while(name[j] !=' '){
				j++;
			}

			j++;

			cout<<(char)toupper(name[j]);

			j++;

			while(name[j] != '-'){
				cout<<(char)tolower(name[j]);
				j++;
			}

			cout<<endl;

		}else if(spaces == 2){

			j=0;

			cout<<(char)toupper(name[0]);
			cout<<". ";

			while(name[j] != ' '){
				j++;
			}

			j++;

			cout<<(char)toupper(name[j]);
			cout<<". ";

			while(name[j] !=' '){
				j++;
			}			

			j++;

			cout<<(char)toupper(name[j]);

			j++;

			while(name[j]!='-'){
				cout<<(char)tolower(name[j]);
				j++;
			}

			cout<<endl;

		}

	}

	return 0;
}