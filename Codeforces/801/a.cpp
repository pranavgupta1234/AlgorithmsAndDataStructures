#include <bits/stdc++.h>

#define ll long long 

using namespace std;
string str;
int c;
bool f = false;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>str;
    for(int i=0 ; i<str.length()-1 ; i++){
        if(str[i] == 'V' and str[i+1] == 'K') c++;
    }
    for(int i=0 ; i<str.length()-1 ; i++) if(str[i] == str[i+1] and str[i+1] != str[i+2])  f = true; 
    return 0;
}