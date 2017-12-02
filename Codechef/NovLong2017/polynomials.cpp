#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

long long evalHorner(vector<int>& coeff, int point){
	long long val = coeff[3];
	for (int i=2; i>=0; i--){
		val = val*point + coeff[i];
	}
	return val;
}

long long eval(vector<int>& coeff,int point){
	long long val = 0;
	for(int i=0 ; i<4 ; i++){
		val += coeff[i]*pow(point,i);
	}
	return val;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector< vector<int> > coeff(n,vector<int>(4,0));
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<4 ; j++){
				cin>>coeff[i][j];
			}
		}
		int q;
		cin>>q;
		while(q--){
			int point;
			cin>>point;
			long long minval = LONG_LONG_MAX;
			for(int i=0 ; i<n ; i++){
				minval = min(minval,evalHorner(coeff[i],point));
			}
			cout<<minval<<endl;	
		}	
	}

	return 0;
}