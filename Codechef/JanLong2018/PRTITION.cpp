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
				vector<int> act;
    			vector<int> part1;
				vector<int> part2;
				ll sum1 = 0;
				ll sum2 = 0;
    			for(int i=n ; i>=1 ; i--){
    				if(i != x){
						act.push_back(i);
    				}
    			}
				bool diff = true;
				for(int i=0 ; i<act.size() ;){
					sum1 += act[i];
					bin[act[i]] = 1;
					if(diff) i+=3,diff = false;
					else i+=1,diff = true;
				}
				sum2 = 2*s - sum1;
				for(int i=n ; i>=1 ; i--){
					if(i != x){
						if(bin[i] == 1)  part1.push_back(i);
						else part2.push_back(i);
					}
				}
				bool iseq = false;
				for(int i=0 ; i<=part1.size() ; i++){
					for(int j=0 ; j<=part2.size() ; j++){
						if(sum1 == sum2) { iseq = true; break;}
						else{
							if(sum1 - part1[i] + part2[j] == sum2 - part2[j] + part1[i]){
								sum1 -= part1[i];
								sum2 -= part2[j];
								swap(part1[i],part2[j]);
								swap(bin[part1[i]],bin[part2[j]]);
								sum1 += part1[i];
								sum2 += part2[j];
							}
						}
					}
					if(iseq) break;
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