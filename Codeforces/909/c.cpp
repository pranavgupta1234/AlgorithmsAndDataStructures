#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	deque<char> comm(n);
	vector<int> fpos;
	for(int i=0 ; i<n ; i++){
		cin>>comm[i];
	}

	while(!comm.empty()){
		if(comm[0] == 's'){
			comm.pop_front();
		}else{
			break;
		}
	}

	if(comm.size() != 0){
		while(comm[comm.size()-1] == 's'){
			comm.pop_back();
		}
		comm.push_back('s');
	}else{
		comm.push_back('s');
	}


	int fs = 0;
	int ss = 0;

	for(int i=0 ; i<comm.size() ; i++){
		if(comm[i] == 'f'){
			fpos.push_back(i);
		}
	}

	for(int i=0 ; i<comm.size()-1 ; i++){
		if(comm[i] == 'f' and comm[i+1] == 's'){
			fs++;
		}
	}

	for(int i=0 ; i<fpos.size()-1 ; i++){
		int scount = 0 ;
		for(int j=fpos[i] ; j<fpos[i+1] ; j++){
			if(comm[j] == 's'){
				scount++;
			}
			if(scount >= 2){
				ss++;
				break;
			}
		}
	}

	fs = fs <= 0 ? 1 : fs; 
	ss = ss <= 0 ? 1 : ss;

	int ans1 = 1;
	int ans2 = 1;
	int ans = 0;

	for(int i=0 ; i<fs-1 ; i++){
		ans1 = (ans1*2)%mod;
	}

	for(int i=0 ; i<ss-1 ; i++){
		ans2 = (ans2*2)%mod;
	}

	ans = (ans1 + ans2)%mod; 



	cout<<ans<<endl;

	return 0;
}