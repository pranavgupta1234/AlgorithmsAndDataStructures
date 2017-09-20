#include <iostream>
#include <queue>
#include <cmath>

#define lli long long int

using namespace std;

int main(){
	
	int n,m;
	cin>>n>>m;
	
	priority_queue<lli> set;
	priority_queue<lli> setCopy;
	vector<lli> result;
	vector<lli> remains;
	
	for(int i=0 ; i<n ; i++){
		lli temp;
		cin>>temp;
		set.push(temp);
	}	
	int operations = 1;
	int c = set.top();

	setCopy.push(c/2);
	set.pop();
	result.push_back(c);

	while(!set.empty()){

		bool flag = true;
		operations++;
		lli maxnum = 0;
		lli top1 = set.top();
		lli top2 = setCopy.top();

		if(top1 != top2){
			maxnum = max(top1,top2);
		}else{
			maxnum = top1;
			flag = false;
		}

		lli half = maxnum/2;

		if(flag){
			if(maxnum == top1){
				set.pop();
			}else{
				setCopy.pop();
			}
		}else{
			set.pop();
		}
		
		if(half != 0){
			setCopy.push(half);		
		}

		result.push_back(maxnum);	

	}

	//cout<<operations<<endl;
/*	for(int i=0 ; i<result.size() ; i++){
		cout<<result[i]<<" ";
	}

	cout<<endl;*/

	while(!setCopy.empty()){
		lli t = setCopy.top();
		remains.push_back(t);
		setCopy.pop();
	}

	for(int i=0 ; i<m ; i++){
		int q;
		cin>>q;
		if(q>=1 and q<=operations){
			cout<<result[(q-1)%operations]/(int)pow(2,(q-1)/operations)<<endl;
		}else{
			cout<<remains[(q-1)%operations]/(int)pow(2,(q-1)/operations - 1)<<endl;			
		}
	}

	return 0;
}