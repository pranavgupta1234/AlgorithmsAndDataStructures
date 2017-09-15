#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	
	int n,k;
	cin>>n>>k;
	map<int,int> cost;
	map<int,int> delayed_schedule; 
	
	for(int i=0 ; i<n ; i++){
		int temp;
		cin>>temp;
		cost[i+1] = temp;
	}

	for(int i=k+1 ; i<=k+n ; i++){
		int flight_no;
		int max_no = 0;
		map<int,int> :: iterator it = cost.begin();

		while(it -> first <= i){

			if(cost[it -> second] > max_no){
				max_no = cost[it -> second];
				flight_no = it -> first;	
			}
			it++;

		}
		delayed_schedule[i] = flight_no;
		cost.erase(flight_no);
	}

/*	for(map<int,int> :: iterator it = delayed_schedule.begin() ; it != delayed_schedule.end() ; it++){
		cout<<it -> first<<" "<<it -> second<<endl;
	}*/


	return 0;
}