#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){
		int n,q;
		cin>>n>>q;
		int p1,p2;
		int color[n+1];

		//initialise color matrix ith index -> color of  ith node except 0
		for(int i=0 ; i<=n ; i++){
			color[i]=0;
		}

		//tree representation
		vector<vector<int> > tree(n,vector<int>(0,0));

		for(int i=0 ; i<n-1 ; i++){
			cin>>p1>>p2;
			tree[p1-1].push_back(p2-1);
			tree[p2-1].push_back(p1-1);
		}

		for(int i=0 ; i<n ; i++){
			int bit;
			cin>>bit;
			color[i+1] = bit;
		}

		for(int k=0 ; k<q ; k++){
			int s,b;
			cin>>s>>b;
			int pathl = 0;
			int blackNodes = 0;
			bool result = false;
			
			for(int i=0 ; i<n ; i++){
				if(tree[i].size() >= s){
					if(color[i+1] == 1){
						blackNodes++;
					}
					for(int j=0 ; j<s-1 ; j++){
						if(color[tree[i].at(j)+1] == 1){
							blackNodes++;
						}
					}
					if(blackNodes == b){
						result = true;
						break;
					}					
				}
			}
			cout<<(result ? "YES" : "NO")<<endl;
		}
	}

	return 0;
}