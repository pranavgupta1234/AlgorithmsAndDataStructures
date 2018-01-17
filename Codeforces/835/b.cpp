#include <bits/stdc++.h>

#define ll long long

using namespace std;

int k;
deque<int> num;
string n; 
ll sum = 0;
ll digits = 0;

int main(){
	cin>>k;
	cin>>n;
	for(int i=0; i<n.length() ; i++){
		num.push_back(n[i]-'0');
		sum	+= n[i]-'0'; 
	}
	int j = 0;
	if(sum < k){
		sort(num.begin(),num.end());
		while(sum < k){
			digits++;
			sum += (9 - num[j]);
			j++;
		}
		cout<<digits<<endl;
		return 0;
	}

	cout<<"0"<<endl;

	return 0;
}