#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int x,h,m;
int y = 0;

bool lucky(int h,int m){
    string hh = to_string(h);
    string mm = to_string(m);
    if(find(hh.begin(),hh.end(),'7') != hh.end()) return true;
    if(find(mm.begin(),mm.end(),'7') != mm.end()) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>x;
    cin>>h>>m;
    while(!lucky(h,m)){
        y++;
        if(m-x < 0){
            if(h > 0 ) h--;
            else h = 23;
            m = 60 - (x-m);
        }else {
            m = m-x;
        } 
    }
    cout<<y<<endl;
    return 0;
}