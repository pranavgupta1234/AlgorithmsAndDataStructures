#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define ll long long 

#define FAST_IO ios_base::sync_with_stdio 

using namespace std;

int main(){
	FAST_IO(false);
	int n;
	cin>>n;
	int mindiff = 0;
	vector<int> s;
	ll total = n*(n+1)/2;
	
	if(total & 1){
		mindiff = 1;
		int no = ((int)sqrt(1+4*total)-1)/2;
		for(int i=1 ; i<=no ; i++){
			s.push_back(i);
		}
		int curr_sum = no*(no+1)/2;

		for(int i=no ; i<=n ; i++){
			int new_sum = curr_sum + no;
			if(find(s.begin(),s.end(),new_sum-(total/2 + 1)) != s.end()){
				s.erase(find(s.begin(),s.end(),new_sum-(total/2 + 1)));
				s.push_back(no);
			}
			if(new_sum == total/2){
				break;
			}
		}

		cout<<mindiff<<endl;
		cout<<s.size()<<" ";
		for(int i=0 ; i<s.size() ; i++){
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}else{
		mindiff = 0;
		for(int i=1 ; i<=n/4 ; i++){
			s.push_back(i);
		}
		for(int i=n ; i > n-n/4 ; i--){
			s.push_back(i);
		}
		cout<<mindiff<<endl;
		cout<<s.size()<<" ";
		for(int i=0 ; i<s.size() ; i++){
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}

}