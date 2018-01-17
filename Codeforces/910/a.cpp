#include <bits/stdc++.h>

using namespace std;

int n,d;
char arr[150];
int steps,start=1,curr=1,m;
int main(){
	cin>>n>>d;
	for(int i=1 ; i<=n ; i++){
		cin>>arr[i];
	}

	while(curr < n){
		curr = start;
		m = start + d;
		int temp = curr;
		while(curr <= m){
			if(arr[curr] == '1'){
				start = curr;
			} 
			curr++;
		}
		curr -= 1;
		if(temp == start and curr < n)	cout<<"-1"<<endl , exit(0);
		else steps++;
	}

	cout<<steps<<endl;

	return 0;
}