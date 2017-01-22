#include <bits/stdc++.h>
using namespace std;
int maxVal(vector<int> &,int);
int main(){
    vector<int> a = {1,5,8,9,10,17,17,20};
    cout<<maxVal(a,a.size())<<endl;
	return 0;
}
int maxVal(vector<int> &price,int size){
	int cutRod[size+1][size+1];

	for(int i=0;i<=size;i++){
		cutRod[0][i]=0;
	}
	for(int i=0;i<=size;i++){
		cutRod[i][0]=0;
	}
	
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(i>=j){
                cutRod[i][j]=max(cutRod[i][j-1],cutRod[i-j][j]+price[j-1]);
            }else{
                cutRod[i][j]=cutRod[i][j-1];
            }        
		}
	}
	for(int i=0;i<=size;i++){
		for(int j=0;j<=size;j++){
            cout<<cutRod[i][j]<<" ";
		}
		cout<<endl;
	}
	return cutRod[size][size-1];
}
