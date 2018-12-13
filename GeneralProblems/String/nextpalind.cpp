#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    vector<char> v(n,' ');
	    for(int i=0 ; i<n ; i++) cin>>v[i];
	    string str(v.begin(), v.end());
        string ans ;
        if(n&1){
            char mid ;
            string p1(str.begin(),str.begin()+n/2);
            mid = str[n/2];
            string p2(str.begin()+n/2 + 1,str.end());
            string s = p1;
            reverse(s.begin(), s.end());
            if(s > p2) {
                ans = p1 + mid + s;
            }else{
                if(mid >= '0' and mid <= '8'){
                    mid++;
                    ans = p1 + mid + s;
                }else{
                    mid = '0';
                    int i = n/2-1, j= n/2 + 1;
                    ans = p1 + mid + s;
                    while(i >= 0 and j < n){
                        if(ans[i] == '9'){
                            ans[i] = '0';
                            ans[j] = '0';
                            i--;
                            j++;
                        }else{
                            ans[i]++;
                            ans[j]++;
                            break;
                        }
                    }
                }    
            }
        }else{
            string p1(str.begin(),str.begin()+n/2);
            string p2(str.begin()+n/2,str.end());
            string s = p1;
            reverse(s.begin(), s.end());
            if(s > p2) {
                ans = p1 + s;
            }else{
                ans = p1 + s;
                int i = n/2 - 1;
                int j = n/2;
                while(i >= 0 and j < n){
                    if(ans[i] == '9'){
                        ans[i] = '0';
                        ans[j] = '0';
                        i--;
                        j++;
                    }else{
                        ans[i]++;
                        ans[j]++;
                        break;
                    }
                }
            }
        }
        int len = ans.length();
        int z = 0;
        for(int i=0 ; i<len ; i++) if(str[i] == '0') z++;
        if(z == len){
            ans[ans.length()-1] = '1';
            ans = "1" + ans;
        }
        for(auto i : ans) cout<<i<<" ";
        cout<<endl;
	}
	
	return 0;
}