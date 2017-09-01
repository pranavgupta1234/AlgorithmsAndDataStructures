#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
	
	int t;
	cin>>t;

	set<int> permutations;
	
	while(t--){

		permutations.clear();
		set<int> :: iterator it;
		vector<int> ans;

		int n;
		cin>>n;
		int invalid_index=1;

		for(int i=0 ; i<n ; i++){
			permutations.insert(i+1);
		}
		
		/*for(it = permutations.begin() ; it!=permutations.end() ; it++){
			cout<<*it<<" ";
		}*/

		while(permutations.size() != 1){

			it = permutations.begin();
			int temp;

			if(*it == invalid_index){
				temp = *it;
				permutations.erase(it);

				set<int> :: iterator start;
				start = permutations.begin();
				ans.push_back(*start);
				//cout<<*start<<" ";
				permutations.erase(start);
				invalid_index++;
				permutations.insert(temp);

			}else{
				set<int> :: iterator s;
				s = permutations.begin();
				//cout<<*s<<" ";
				ans.push_back(*s);
				permutations.erase(s);
				invalid_index++;
			}

		}

		if(n&1){
			int temp = ans[ans.size()-1];
			ans[ans.size()-1] = ans[ans.size()-2]+1;
			ans.push_back(temp);
		}else{
			ans.push_back(ans[ans.size()-1]-1);
		}

		for(int i=0 ; i<ans.size() ; i++){
			cout<<ans[i]<<" ";
		}

		cout<<endl;
		
	}	

	return 0;
}