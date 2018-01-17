#include <bits/stdc++.h>

using namespace std;

int main(){
	int s,v1,v2,t1,t2;
	cin>>s>>v1>>v2>>t1>>t2;

	if(2*t1 + s*v1 == 2*t2 + s*v2){
		cout<<"Friendship"<<endl;
	}else if(2*t1 + s*v1 < 2*t2 + s*v2){
		cout<<"First"<<endl;;
	}else{
		cout<<"Second"<<endl;
	}
}