#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int* arr;
int* bit;

void update(int x,int val){
	for(; x<= n ; x +=x&(-x)){
		bit[x] += val;
	}
}

int query(int x){
	int sum = 0;
	for(; x>=1 ; x-=x&(-x)){
		sum += bit[x];
	}
	return sum;
}

int main(){
	cin>>n;
	arr = new int[n+1];
	bit = new int[n+1];
	memset(arr,0,sizeof(arr[0])*(n+1));
	memset(bit,0,sizeof(bit[0])*(n+1));
	for(int i=1 ; i<=n ; i++){
		cin>>arr[i];
		update(i,arr[i]);
	}
	cout<<query(4)<<endl;
	return 0;
}