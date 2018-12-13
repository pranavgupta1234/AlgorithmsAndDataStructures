#include <bits/stdc++.h>

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int q;
    cin>>q;
    map<int,int> m;
    int i = 0, j = 1;
    while(q--){
        char x;
        int v;
        cin>>x>>v;
        if(x == 'R'){
            m[v] = j;
            j++;
        }
        if(x == 'L'){
            m[v] = i;
            i--;
        }
        if(x == '?'){
            cout<<min(abs(j-1-m[v]), abs(i-m[v]+1))<<endl;
        }
    }


    return 0;
}