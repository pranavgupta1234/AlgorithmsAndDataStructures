#include <bits/stdc++.h>

using namespace std;

string s;
int prefa[5500];
int prefb[5500];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	int a=0,b=0;
	int mx = 0;
	for(int i=1 ; i<=s.length() ; i++){ if(s[i-1] == 'a') { a++ ; }  prefa[i] = a; } 
	for(int i=1 ; i<=s.length() ; i++){ if(s[i-1] == 'b') { b++ ; }  prefb[i] = b; }
	for(int i=0 ; i<=s.length() ; i++){
		for(int j=i ; j<=s.length() ; j++){
			mx = max(mx,(prefa[s.length()]-prefa[j])+(prefb[j]-prefb[i])+prefa[i]);
		}	
	}
	cout<<mx<<endl;
	return 0;
}