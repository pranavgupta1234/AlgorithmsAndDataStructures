#include <iostream>
#include <string>
#include <cstring>
#define range 2000010
#define rangeN 1000000

using namespace std;

long long oddevendiff(long long i){
	string num = to_string(i);
	int oddsum = 0;
	int evensum = 0;
	for(int j=0 ; j<num.size() ; j++){
		if((num[j]-'0') & 1){
			oddsum += num[j] - '0';
		}else{
			evensum += num[j] -  '0';
		}
	}
	return abs(oddsum-evensum);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	long long hashedSeries[range];
	long long sumSeries[rangeN+1];
	memset(sumSeries,0,sizeof(sumSeries[0])*(rangeN+1));	
	memset(hashedSeries,0,sizeof(hashedSeries[0])*range);
	for(int i=1 ; i<=range ; i++){
		hashedSeries[i] = oddevendiff(i+1);
	}
	sumSeries[1] = hashedSeries[1];
	sumSeries[2] = 12;
	sumSeries[3] = 36;
	sumSeries[4] = 80;
	long long stripsum = 26;
	for(int i=5 ; i<=rangeN ; i++){
		stripsum -= hashedSeries[i-1];  
		sumSeries[i] = sumSeries[i-1] + hashedSeries[2*i-1] + 2*hashedSeries[2*i-2] + 2*stripsum;
		stripsum += hashedSeries[2*i-2] + hashedSeries[2*i-1];
	}
	while(t--){
		long long n; 
		cin>>n;
		cout<<sumSeries[n]<<endl;
	}
	return 0;	
} 