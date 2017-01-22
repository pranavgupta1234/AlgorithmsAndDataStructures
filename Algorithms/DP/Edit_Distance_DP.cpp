#include <bits/stdc++.h>
using namespace std;
int minOperations(string str1,string str2,int size1,int size2);
int main(){
    string str1 = "sunday";
    string str2 = "saturday";
    cout<<minOperations(str1,str2,str1.length(),str2.length())<<endl;
	return 0;
}
int minOperations(string str1,string str2,int size1,int size2){
    int minOp[size2+1][size1+1];
    for(int i=0;i<=size2;i++){
    	minOp[i][0]= i;
    }
    for(int i=0;i<=size1;i++){
    	minOp[0][i]=i;
    }

    for(int i=1;i<=size2;i++){
    	for(int j=1;j<=size1;j++){
    		if(str2[i-1]!=str1[j-1]){
    			minOp[i][j] = min(minOp[i][j-1],min(minOp[i-1][j-1],minOp[i-1][j]))+1;
    		}
    		else{
    			minOp[i][j]=minOp[i-1][j-1];
    		}
    	}
    }
    for(int i=0;i<=size2;i++){
    	for(int j=0;j<=size1;j++){
            cout<<minOp[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return minOp[size2][size1];
}