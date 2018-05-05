#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int lov = 0;
        int c=0,h=0,e=0,f=0;
        for(int i=0 ; i<s.length() ; i++){
            c=0,h=0,e=0,f=0;
            if(s[i] == 'c' or s[i] == 'h' or s[i] == 'e' or s[i] == 'f'){
                for(int j=i ; j<i+4 ; j++){
                    if(s[j] == 'c') c++;
                    else if(s[j] == 'h') h++;
                    else if(s[j] == 'e') e++;
                    else if(s[j] == 'f') f++;
                    else break; 
                } 
                if(c == 1 and h == 1 and e == 1 and f==1) lov++;
            }
        }
        cout<<(lov != 0 ? "lovely "+to_string(lov) : "normal")<<endl;  
    }
    return 0;
}