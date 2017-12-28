#include <iostream>
#include <vector>
#include <cmath>

#define MAXSIZE 10000
#define MAXSQROOTSIZE 100

int arr[MAXSIZE];
int block[MAXSQROOTSIZE];
int blk_size = 0;

using namespace std;

//O(1) update query
void update(int idx,int val){
	block[idx/blk_size] -= arr[idx];
	arr[idx] = val;
	block[idx/blk_size] += arr[idx];
}

// l and r inclusive
int query(int l,int r){
	int sum = 0;
	int i = l;
	while(i%blk_size != 0 and i>=0 and i<=r){	
		sum += arr[i];
		i++;
	}
	int blocks_covered = r/blk_size;
	for(int j = i/blk_size ; j<blocks_covered ; j++){
		sum += block[j];
		i += blk_size;
	}
	while(i <= r){
		sum += arr[i];
		i++;
	}
	return sum;
}

void buildarr(int inputarr[],int n){
	int blk_idx = -1;
	blk_size = sqrt(n);
	for(int i=0 ; i<n ; i++){
		arr[i] = inputarr[i];
		if(i % blk_size == 0){
			blk_idx++;
		}
		block[blk_idx] += arr[i];
	}
}

int main(){
	
	int inputarr[] = {1 , 5 , 6 , 7 , 3 , 9 , 2 , 8};
	int n = sizeof(inputarr)/sizeof(inputarr[0]);

	buildarr(inputarr,n);
	cout<<query(3,6)<<endl;
	update(1,8);
	update(5,8);
	cout<<query(3,6)<<endl;

	return 0;
}