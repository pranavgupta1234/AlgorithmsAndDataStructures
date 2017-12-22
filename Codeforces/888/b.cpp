#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	long finalx = 0;
	long finaly = 0;
	for(int i=0 ; i<str.length() ; i++){
		if(str[i] == 'U'){
			finaly++;
		}else if(str[i] == 'D'){
			finaly--;
		}else if(str[i] == 'L'){
			finalx--;
		}else{
			finalx++;
		}
	}  

	cout<<n-abs(finalx)-abs(finaly)<<endl;
	return 0;
}