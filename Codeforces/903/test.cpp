#include <bits/stdc++.h>
using namespace std;

int main(){
	int h1,a1,c,h2,a2;
	string s="";
	int count = 0;
	cin>>h1>>a1>>c;
	cin>>h2>>a2;
	while(h2>0)
	{
		if(h1>a2 || h2<=a1){
			h2=h2-a1;
			h1=h1-a2;
			s+="STRIKE\n";
			count++;
		}else{
			h1=h1+c-a2;
			s+="HEAL\n";
			count++;
		}
	}
	cout<<count<<endl;
	s.pop_back();
	cout<<s<<endl;
	return 0;
}     