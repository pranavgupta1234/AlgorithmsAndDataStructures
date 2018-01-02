#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> sch[n+1];

	for(int i=1 ; i<=n ; i++){
		int a,d;
		cin>>a>>d;
		sch[i].push_back(a);
		sch[i].push_back(d);		
	}
	
	long ans = sch[1].at(0);
	long next = 0;
	for(int i=2 ; i<=n ; i++){
		if(ans - sch[i].at(0) < 0){
			next = 0;	
		}else{
			next = (ans - sch[i].at(0))/sch[i].at(1) + 1;
		}
		ans = sch[i].at(0) + next*sch[i].at(1);
		//cout<<next<<" "<<ans<<endl;
	}

	cout<<ans<<endl;

	return 0;
}