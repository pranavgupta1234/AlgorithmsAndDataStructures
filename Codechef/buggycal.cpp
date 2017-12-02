#include <iostream>
using namespace std;
int main(){
	
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		string c;
		while(a>0 or b>0){
			c+=(a%10+b%10)%10+48;
			a/=10;
			b/=10;
		}
		int flag=1;
		if(a>0){
		 	cout<<a;
		  	flag=0;
		}
		else if(b>0){
		 	cout<<b;
		 	flag=0;
		}
		for(int i=c.length()-1;i>=0;i--){
			if(c[i]=='0'){
				if(!flag){
					cout<<c[i];
				}
			}
			else{
				flag=0;
				cout<<c[i];
			}
		}
		if(flag==1) cout<<"0";
		cout<<endl;
	}
	return 0;
}