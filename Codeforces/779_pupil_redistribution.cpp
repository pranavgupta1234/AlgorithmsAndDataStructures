#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	vector<int> a;
	vector<int> b;
	int temp;
	int sum =0;
	int ans;
	int freq_a[6]= {0,0,0,0,0,0};
	int freq_b[6] = {0,0,0,0,0,0};

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		a.push_back(temp);
	}
	for(int i=0;i<n;i++){
		cin>>temp;
		b.push_back(temp);
	}
	for(int i=0;i<n;i++){
		freq_a[a[i]]+=1;
		freq_b[b[i]]+=1;
	}
	// for(int i=0;i<6;i++){
	// 	cout<<freq_a[i]<<" "<<freq_b[i]<<endl;
	// }
	for(int i=1;i<=5;i++){
		temp=0;
		temp=freq_a[i]+freq_b[i];
		if(temp % 2!=0){
			sum=-1;
			break;
		}
		temp=temp/2;
		sum+=abs(temp-freq_a[i]);
	}
	if(sum%2==0){
		cout<<sum/2<<endl;
	}else{
		cout<<sum<<endl;
	}


}