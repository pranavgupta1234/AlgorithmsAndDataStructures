#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		char ch=0;
		vector<int> arr;
		vector<int> :: iterator it;

		while(ch != '\n'){
			int temp;
			cin>>temp;
			arr.push_back(temp);
			ch = getchar();
		}

		it = find(arr.begin(),arr.end(),arr.size()-1);

		arr.erase(it);
		vector<int> :: iterator i = max_element(arr.begin(),arr.end());
		cout << *i << endl;

	}

	return 0;
}