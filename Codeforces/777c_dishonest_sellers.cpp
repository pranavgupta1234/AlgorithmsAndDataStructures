#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int temp;
	int sum=0;
	vector<int> current;
	vector<int> after;
	vector<int> difference;
	map<int,int> diff_to_index;
	

	for(int i=0;i<n;i++){
		cin>>temp;
		current.push_back(temp);
	}
	//In case we definitely know the size of vector we can avoid calling the function of template class as it will add to time complexity
	for(int i=0;i<n;i++){
		cin>>temp;
		after.push_back(temp);
	}
	/*map[key] = value; there's no way to tell if you replaced the value for key, or if you created a new key with value, map::insert() will only create */

	for(int i=0;i<n;i++){
		difference.push_back(current[i]-after[i]);
		diff_to_index[current[i]-after[i]]=i;
	}

	sort(difference.begin(),difference.end());
	for(int i=0;i<n;i++){
		cout<<difference[i]<<" ";
	}
	cout<<endl;

	for(int i=0;i<k;i++){
		sum+= current[diff_to_index[difference[i]]];
	}
	for(int i=k;i<n;i++){
		if(difference[i]<0){
			sum+= current[diff_to_index[difference[i]]];
		}
		else{
			sum+= after[diff_to_index[difference[i]]];
		}
	}

	cout<<sum<<endl;

	return 0;
}