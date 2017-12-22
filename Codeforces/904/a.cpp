#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;	
	int arr[m+1];
	memset(arr,0,sizeof(arr[0])*(m+1));
	int ai[n];
	int bi[n];
	bool flag = true;
	for(int i=0 ; i<n ; i++){
		cin>>ai[i]>>bi[i];
	}
	if(ai[0] != 0){
		flag = false;
	}else{
		arr[0] = 1;
		for(int i=0 ; i<n ; i++){
			if(arr[ai[i]] != 1){
				flag = false;
				break;
			}else{
				for(int j=ai[i] ; j<=bi[i] ; j++){
					arr[j] = 1;
				}
			}
		}
		if(arr[m] == 1){
			flag = true;
		}else{
			flag = false;
		}
	}

	cout<<(flag ? "YES" : "NO")<<endl;

	return 0;
}