#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int arr[10000];
int bit[10000];

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
	memset(arr,0,sizeof(arr[0])*10000);
	memset(bit,0,sizeof(bit[0])*10000);
	cin>>n;
	for(int i=1 ; i<=n ; i++){
		cin>>arr[i];
		update(i,arr[i]);
	}
	cout<<query(2)<<endl;
	return 0;
}