#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll x,n;
		cin>>x>>n;
		int bin[n+1];
		for(int i=0 ; i<=n ; i++) bin[i] = 0; 
		ll s = n*(n+1)/2 - x;
		if(s % 2 != 0 or n==2 or n==3) cout<<"impossible"<<endl;
		else{
			s = s/2;
			ll sum = 0;
			for(int i=n ; i>=1 ; i--){
				if(sum == s)	break;
				else{
					if(i != x)	{	bin[i] = 1;  sum += i; } 
					if(sum > s){
						sum -= i;
						bin[i] = 0;
						if(s - sum != x){ 
							bin[s-sum] = 1;
							sum = s;
						}
					} 
				}
			}
			
			if(bin[1] == 1) for(int i=1 ; i<=n ; i++) bin[i] = 1 - bin[i]; 
			
			for(int i=1 ; i<=n ; i++){
				if(i != x) cout<<bin[i];
				else cout<<"2";
			}	
			cout<<endl;
		}
	}
	return 0;
}