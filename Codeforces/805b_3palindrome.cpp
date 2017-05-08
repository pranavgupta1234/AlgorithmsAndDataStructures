#include <iostream>

using namespace std;

int main(){
	
	int n;
	cin>>n;
	int counter = 0;
	int t = n%4;
	counter = n - t;
	
	while(counter){

		cout<<"aabb";
		counter -= 4;

	}

	if(t > 0){
		cout<<'a';
		t--;
	}else{

		cout<<endl;
		return 0;

	}

	if(t > 0){
		cout<<'a';
		t--;
	}else{
		cout<<endl;
		return 0;
	}

	if(t > 0){
		cout<<'b';
		t--;
	}else{
		cout<<endl;
		return 0;
	}

	if(t > 0){
		cout<<'b';
		t--;
	}else{
		cout<<endl;
		return 0;
	}
	
	return 0;
}