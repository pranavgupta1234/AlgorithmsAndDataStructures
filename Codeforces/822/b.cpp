#include <iostream>
#include <vector>
#include <string>

using namespace std;

int match_string(string,string,int,vector<int>&);

int main(){
	
	string s;
	string t;

	int n,m;

	int count = 0;
	vector<int> pos(0,0);
	vector<int> ans(0,0);
	int res = 0;
	cin>>n>>m;
	cin>>s>>t;

	while(count <= m-n){

		int common = match_string(s,t,count,pos);

		if( common >= res){
			res = common;
			ans.clear();
			for(int i=0 ; i< pos.size() ; i++){
				ans.push_back(pos[i]);
				//cout<<pos[i]<<" ";
			}
			//cout<<endl;
			pos.clear();
		}else{
			pos.clear();
		}
		count++;
	}

	cout<<n-res<<endl;
	for(int i=0 ; i< n-res ; i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}

int match_string(string s,string t,int start,vector<int>& pos){

	int score = 0;

	for(int i=0 ; i<s.size() ; i++){
		if(s[i]==t[start+i]){
			score++;
		}else{
			pos.push_back(i+1);
		}
	}

	return score;
}