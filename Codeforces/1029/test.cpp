#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	string t;
	cin.ignore();
	cin>>t;
	string temp;
	temp.clear();
	int p=0;
	for(int i=0; i<n-1; i++){
		temp=t[n-i-1]+temp;
		//cout<<temp<<endl;
		if(temp == t.substr(0,i+1)){
			p=i+1;
			//cout<<p<<" "<<t.substr(0,i+1)<<endl;
		}
		
	}
	string s;
	s.clear();
	s=t;
	for(int i=1; i<k; i++){
		s=s+t.substr(p,n-p);
	}
	cout<<s<<endl;
	return 0;
}