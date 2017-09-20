#include <iostream>
#include <set>

using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		set<int> seta;
		set<int> setb;

		for(int i=0 ; i<n ; i++){
			int temp;
			cin>>temp;
			seta.insert(temp);
		}

		for(int i=0 ; i<n ; i++){
			int temp;
			cin>>temp;
			setb.insert(temp);
		}
		set<int> :: iterator it1 = seta.begin();
		set<int> :: iterator it2 = setb.begin();
		for( ; it1 != seta.end() and it2 != setb.end() ; it1++ , it2++){
			cout<<*it1<<" ";
			cout<<*it2<<" ";
		}

		cout<<endl;

	}


	return 0;
}