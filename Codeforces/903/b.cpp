#include <iostream>
#include <vector>

using namespace std;

int main(){
	int h1,a1,c1;
	int h2,a2;
	cin>>h1>>a1>>c1;
	cin>>h2>>a2;
	vector<char> strategy(0,0);
	while(h2>0){
		
	}
	cout<<strategy.size()<<endl;
	for(int i=0 ; i<strategy.size() ; i++){
		if(strategy[i] == 's'){
			cout<<"STRIKE"<<endl;
		}else{
			cout<<"HEAL"<<endl;
		}
	}
	return 0;
}