#include <bits/stdc++.h>

using namespace std;

char str[100005];

int main(){
	int n;
	cin>>n;
	int cnt1 = 0;
	int cnt0 = 0;
	int bal[n];
	int minIndex[n];
	int m = 0;
	for(int i=0 ; i<n ; i++){
		cin>>str[i];
		str[i] == '1' ? cnt1++ : cnt0++;
		bal[i] = abs(cnt1-cnt0);
	}

	for(int i=0 ; i<n ; i++){
		cout<<bal[i];
	}
	cout<<endl;
	cout<<m<<endl;

	return 0;
}