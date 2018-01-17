#include <bits/stdc++.h>

using namespace std;

int n;
int lab[55][55];
bool good = true;

bool check(int i,int j,int val){
	for(int k=1 ; k<=n ; k++)
		if(k != i)
		for(int p=1 ; p<=n ; p++)
			if(p != j)
			if(lab[k][j] + lab[i][p] == val) return true;
	

	return false;
}

int main(){
	cin>>n;
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			cin>>lab[i][j];
		}
	}

	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			if(lab[i][j] != 1){
				good = good and check(i,j,lab[i][j]);
			}
			if(good == false){
				break;
			}
		}
		if(!good){
			break;
		}
	}

	cout<<(good ? "Yes" : "No")<<endl;

	return 0;
}
