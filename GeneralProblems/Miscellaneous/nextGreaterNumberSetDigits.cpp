#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		stringstream ss;
		int n;
		cin>>n;
		int n_copy = n;
		vector<int> num;
		ss<<n;
		string numString = ss.str();
		ss.clear();
		vector<int> ans;
		
		while(n_copy){
			int r = n_copy%10;
			num.push_back(r);
			n_copy/=10;
		}

		sort(num.begin(),num.end());
		
		for(int i=0 ; i<num.size()-1 ; i++){
			if(num[i] == numString[0] - '0'){
				ans.push_back(num[i+1]);
				//cout<<num[i+1]<<endl;
				num[i+1] = -1;
				break;
			}
		}

		for(int i=0 ; i<num.size() ; i++){
			if(num[i] != -1){
				ans.push_back(num[i]);
			}
		}
		if(ans[0] < numString[0]-'0'){
			cout<<"not possible"<<endl;
		}else{
			for(int i=0 ; i<ans.size() ; i++){
				cout<<ans[i];
			}
			cout<<endl;
		}
	}



	return 0;
}