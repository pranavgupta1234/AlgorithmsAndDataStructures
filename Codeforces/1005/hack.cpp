#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
    string s;
    cin>>s;
    int ck=0,di;
    int len=s.size();
    int cnt=0;

    for(int i=0; i<len; i++){
        di=s[i]-'0';
        for(int j=i; j>=ck; j--){
            a[j]=(a[j]*10)+di;
            if(a[j]%3==0){
                cnt++;
                ck=i+1;
                break;
            }
        }
        if(i-ck>=17)ck++;
    }
    cout<<cnt<<"\n";
    return 0;
}