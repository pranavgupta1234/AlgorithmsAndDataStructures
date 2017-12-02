#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string createPalindromeOfN(int n){
	bool alt = true;
	string pal = "";
	for(int i=0 ; i<n/2 ; i++){
		if(alt){
			pal += "a";
			alt = false;
		}else{
			pal += "b";
			alt = true;
		}
	}
	string rev = pal;
	reverse(rev.begin(),rev.end());
	if(n&1){
		if(pal[pal.length()-1] == 'a'){
			pal += "b";
		}else{
			pal += "a";
		}
		pal += rev;
	}else{
		pal += rev;
	}
	return pal;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n,p;
		cin>>n>>p;
		string str;
		bool flag = true;
		if(p==1 or (n%2==0 and p==2)){
			flag = false;
		}
		if(flag){
			if(n == p){
				str = createPalindromeOfN(n);
			}else{
				string t = createPalindromeOfN(p);
				for(int i=0 ; i<n/p ; i++){
					str += t; 
				}
			}
		}
		cout<<(flag ? str : "impossible")<<endl;
	}
	return 0;
}