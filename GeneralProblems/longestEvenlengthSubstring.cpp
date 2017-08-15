#include <iostream>
#include <string>

using namespace std;

int findLength(string str,int n){

	int ans = 0;

	for(int i=0 ; i<n-1 ; i++){

		int l = i;
		int r = i+1;

		int lsum=0,rsum=0;

		while(l>=0 and r<n){

			lsum += str[l] - '0';
			rsum += str[r] - '0';

			if(lsum == rsum){
				ans = max(ans,r-l+1);
			}

			l--;
			r++;

		}

	}

	return ans;
}

int main(){
	
	string digits;
	cin>>digits;

	cout<<findLength(digits,digits.length())<<endl;

	return 0;
}