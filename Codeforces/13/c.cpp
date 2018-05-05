#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
priority_queue<int> q;
ll k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n; 
    for(int i=0 ; i <n ; i++){
        int c;
        cin>>c;
        q.push(c);
        if(q.top() > c){
            k += q.top()-c;
            q.pop();
            q.push(c);
        }
    }
    cout<<k<<endl;
    return 0;
}