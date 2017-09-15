#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

void reshuffle(vector<long long int>& arr,long long int k,int n){

	
	if(k == pow(2,n)){
		return ;
	}else{

		queue<long long int> odds;
		long long int partitionsize = arr.size() / (int)pow(2,k);

		for(long long int i=1 ; i<partitionsize ; i+=2){
			odds.push(arr[i]);
		}

		for(long long int i=0 , j = 0; i<partitionsize ; i++,j+=2){
			arr[i] = arr[j];
		}

		for(int i=0 ; i<odds.size() ; i++){
			arr.push_back(odds.front());
			odds.pop();
		}

		reshuffle(arr,++k,n);

	}


}

void print(queue<long long int>& q){
	for(int i=0 ; i<q.size() ; i++){
		long long int a;
		a = q.front();
		cout<<a<<" ";
		q.pop();
		q.push(a);
	}
	cout<<endl;
}

void clear(queue<long long int> &q )
{
	queue<long long int> empty;
	swap( q, empty );
}

int main(){
	
	int q;
	cin>>q;

	while(q--){

		int n;
		long long int k;
		long long int parts;
		long long int a;
		cin>>n>>k;
		vector<long long int> num;

		for(long long int i=0 ; i<pow(2,n) ; i+=2){
			num.push_back(i);
		}

		for(long long int i=1 ; i<pow(2,n) ; i+=2){
			num.push_back(i);
		}

		for(int i=0 ; i<num.size() ; i++){
			cout<<num[i]<<" ";
		}

		cout<<endl;


		int k_copy;

		k_copy = 1;

		while(k_copy < n){

			long long int no_of_part = pow(2,k_copy);
			long long int partSize = pow(2,n - k_copy);

			long long int i=0;

			while(no_of_part--){

				queue<long long int> odds;
				cout<<i<<" ";
				odds = queue<long long int>();

				for(int j=i ; j < i + partSize ; j++){

					for(long long int k=j+1 ; k< i + partSize ; k+=2){
						odds.push(num[k]);
					}	

					for(long long int a=j , b = j; a< i + partSize/2 and b < i + partSize; a++,b+=2){
						num[a] = num[b];
					}

					int c = j;

					while(!odds.empty()){

						num[partSize/2 + c] = odds.front();
						odds.pop();
						c++;

					}	

				}

				i += partSize;

			}

			for(int i=0 ; i<num.size() ; i++){
				cout<<num[i]<<" ";
			}

			cout<<endl;

			k_copy++;
		}

		for(int i=0 ; i<num.size() ; i++){
			cout<<num[i]<<" ";
		}


		cout<<endl;

	}



	return 0;
}