#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	
	int temp;
	vector<int> seq;
	char ch = 100;
	cout<<"Enter the sequence ::"<<endl;
	
	while(ch!=10){
		cin>>temp;
		seq.push_back(temp);
		ch = getchar();
	}

	int *res = new int[seq.size()];

	for(int i=0 ; i<seq.size() ; i++){
		res[i] = 1;
	}
	
	for(int i=1 ; i<seq.size() ; i++){
		for(int j=0 ; j<i ; j++){
			if(seq[j]<seq[i]){
				res[i] = max(res[i],res[j]);
				res[i] = res[j] + 1;
			}
		}
	}

	cout<<res[seq.size()-1];

	return 0;
}