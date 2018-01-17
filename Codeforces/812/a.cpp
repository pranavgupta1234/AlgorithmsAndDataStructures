#include <bits/stdc++.h>

using namespace std;

int light[5][5];
bool safe = true;

inline bool selfsafe(int l){
	if(light[l][4] == 0){
		return true;
	}

	for(int i=1 ; i<=3 ; i++){
		if(light[l][i] == 1){
			return false;
		}
	}

	return true;
}

inline bool othersafe(int l){
	if(light[l][4] == 0){
		return true;
	}else{
		if(light[(l+1)%5][1] == 1) return false;
		if(light[(l+2)%5][2] == 1)	return false;
		if(light[(l+3)%5][3] == 1)	return false;
	}

	return true;
}

int main(){

	for(int i=1; i<=4 ; i++){
		for(int j=1 ; j<=4 ; j++){
			cin>>light[i][j];
		}
	}
	
	//cout<<othersafe(1)<<endl;	
	for(int i=1 ; i<=4 ; i++){
		//cout<<selfsafe(i)<<" "<<othersafe(i)<<endl;
		safe = safe and selfsafe(i) and othersafe(i);
	}

	cout<<(safe ? "NO" : "YES" )<<endl;

	return 0;
}