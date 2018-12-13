#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin>>str;

    int i=0,j=0;
    int n = str.length();
    
    while(i < n){
        while(j < n and str[i] == str[j]){
            j++;       
        }
        char c = 'a';
        while(str[i] == c or (i>0 and str[i-1] == c) or (j<n and str[j] == c)){
            c++;
        }
        int cnt = 0;
        for(int k=i ; k<j ; k++){
            if(cnt & 1) str[k] = c;
            cnt++;
        }
        i = j;
    }

    cout<<str<<endl;

    return 0;
}