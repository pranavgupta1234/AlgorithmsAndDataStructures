#include <bits/stdc++.h>

using namespace std;

int n;
int a[50];
int days[150];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    days[1] = 31,days[2] = 29,days[3] = 31,days[4] = 30,days[5] = 31,days[6] = 30,days[7] = 31,days[8] = 31,
    days[9] = 30,days[10] = 31,days[11] = 30,days[12] = 31;
    for(int  i=13 ; i<=24 ; i++){
        if(i==14) days[i] = days[i+12] = days[i+24] = 28;
        else days[i+12] = days[i+24] = days[i] = days[i-12];
    }
    cin>>n;
    bool m = false;
    bool f = false;
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    for(int i=1 ; i<=48 ; i++){
        f = false;
        if(days[i] == a[1]){
            for(int j=1 ; j<=n ; j++){
                if(a[j] != days[(i+j-1)%48 == 0 ? 48 : (i+j-1)%48]){
                    //cout<<i<<endl;
                    f = true;
                    break;
                } 
            }
            if(!f){ m = true ; break; }
        }        
    }
    if(!m) cout<<"No"<<endl,exit(0);
    cout<<(!f ? "Yes" : "No")<<endl;
    return 0;
}