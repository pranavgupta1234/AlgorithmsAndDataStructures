#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s;
ll c;

bool valid(int i,int j){
    if((s[i] == '(' and s[j] =='?') 
    or (s[i] == '(' and s[j] ==')') 
    or (s[i] == '?' and s[j] =='?') 
    or (s[i] == '?' and s[j] ==')'))
    {
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for(int i=0 ; i<s.length()-1 ; i++){
        if(valid(i,i+1)){
            c++;
            int l = i-1;
            int r = i+2; 
            while(l>=0 and r<s.length() and valid(l,r)){
                c++;
                l--;
                r++;
            }
            cout<<i<<" "<<c<<endl;
        }
    }
    cout<<c<<endl;
    return 0;
}