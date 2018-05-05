#include <bits/stdc++.h>

using namespace std;

int n,k;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    cin>>s;
    int m = 1;
    for(int i=0 ; i<s.length()-1 ; i++){
        int r = i+1;
        bool isa = (s[i] == 'a' ? true : false);
        int swaps = k;
        while((swaps or (s[r] != (isa ? 'b' : 'a'))) and r<s.length()){
            if(isa) {
                if(s[r++] != 'a') swaps--;
            }else {
                if(s[r++] != 'b') swaps--;
            }  
        }
        m = max(m,r-i);
        if(m >= n-i-1) break;
    }
    cout<<m<<endl;
    return 0;
}