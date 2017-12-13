#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define range 100010

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arrA[n];
		int hash[range];
		vector<int> freq1;
		vector<int> freq2;
		unordered_map<int,vector<int> > associations;
		memset(hash,0,sizeof(hash[0])*range);
		for(int i=0 ; i<n ; i++){
			cin>>arrA[i];
			hash[arrA[i]]++;
		}
		for(int i=0 ; i<range ; i++){
			if(hash[i] == 1){
				freq1.push_back(i);
			}
			if(hash[i] == 2){
				freq2.push_back(i);
			}
		}
		//only unique elements
		if(freq2.size() == 0 and freq1.size() != 0){
			if(freq1.size() == 1){
				cout<<n-1<<endl;
				cout<<freq1[0]<<endl;
			}else{
				cout<<n<<endl;
				for(int i=0 ; i<n ; i++){
					cout<<arrA[(i+1)%n]<<" ";
				}
				cout<<endl;
			}
		}else if(freq1.size() == 0 and freq2.size() != 0){
			if(freq2.size() == 1){
				cout<<"0"<<endl;
				for(int i=0 ; i<n ; i++){
					cout<<arrA[i]<<" ";
				}
				cout<<endl;
			}else{
				cout<<n<<endl;
				for(int i=0 ; i<freq2.size() ; i++){
					associations[freq2[i]].push_back(freq2[(i+1)%freq2.size()]); 
					associations[freq2[i]].push_back(freq2[(i+1)%freq2.size()]);
				}
				for(int i=0 ; i<n ; i++){
					int val = associations[arrA[i]].back();
					associations[arrA[i]].pop_back(); 
					cout<<val<<" ";
				}
				cout<<endl;
			}
		}else{
			if(freq2.size() == 1){
				if(freq1.size() == 1){
					cout<<n-1<<endl;
					associations[freq1[0]].push_back(freq2[0]);
					associations[freq2[0]].push_back(freq1[0]);
					associations[freq2[0]].push_back(freq2[0]);
				}else{
					cout<<n<<endl;
					for(int i=0 ; i<2 ; i++){
						associations[freq2[0]].push_back(freq1[i]);
					}
					for(int i=0 ; i<freq1.size()-2 ; i++){
						associations[freq1[i]].push_back(freq1[(i+2)]);
					}
					for(int i=freq1.size()-2 ; i < freq1.size() ; i++){
						associations[freq1[i]].push_back(freq2[0]);
					}
				}
			}else{
				if(freq1.size() == 1){
					cout<<n<<endl;
					for(int i=0 ; i<freq2.size()-1 ; i++){
						associations[freq2[i]].push_back(freq2[(i+1)%freq2.size()]); 
						associations[freq2[i]].push_back(freq2[(i+1)%freq2.size()]);
					}
					associations[freq2[freq2.size()-1]].push_back(freq2[0]); 
					associations[freq2[freq2.size()-1]].push_back(freq1[0]);
					associations[freq1[0]].push_back(freq2[0]);
				}else{
					cout<<n<<endl;
					for(int i=0 ; i<freq2.size() ; i++){
						associations[freq2[i]].push_back(freq2[(i+1)%freq2.size()]); 
						associations[freq2[i]].push_back(freq2[(i+1)%freq2.size()]);
					}
					for(int i=0 ; i<freq1.size() ; i++){
						associations[freq1[i]].push_back(freq1[(i+1)%freq1.size()]);
						associations[freq1[i]].push_back(freq1[(i+1)%freq1.size()]); 
					}
				}
			}
			for(int i=0 ; i<n ; i++){
				int val = associations[arrA[i]].back();
				associations[arrA[i]].pop_back(); 
				cout<<val<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}