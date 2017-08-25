#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

string findPat(int,int);

int main(){
	
	int t;
	cin>>t;

	while(t--){

		long int num;
		cin>>num;
		int i=0;

		char str[60];

		while(num > 0){

			int rem = num % 26;

			if(rem == 0){
				str[i++] = 'Z';
				num = num/26 - 1;
			}else{
				str[i++] = rem - 1 + 'A';
				num = num/26;
			}

		}

		str[i] = '\0';

		reverse(str,str+strlen(str));
		cout<<str<<endl;

	}

	return 0;
}