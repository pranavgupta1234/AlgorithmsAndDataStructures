#include <iostream>
#include <vector>

#define daytime 86400

using namespace std;

int main(){
	int n,t;
	cin>>n>>t;
	int freetime[n];
	for(int i=0 ; i<n ; i++){
		int temp;
		cin>>temp;
		freetime[i] = daytime - temp;
	}
	int daystaken = 0;
	while(t>0){
		t -= freetime[daystaken];
		daystaken++;
	}
	cout<<daystaken<<endl;
	return 0;
}