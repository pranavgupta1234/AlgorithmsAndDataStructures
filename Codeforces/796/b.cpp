#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int tab[1000600];
int holes[1000600];

int main(){
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    cin>>n>>m>>k;
    tab[1] = 1;
    bool drop = false;
    int fpos = 1;
    for(int i=0 ; i<m ; i++){ int t; cin>>t ; tab[t] = -1 ; }
    for(int i=0 ; i<k ; i++){
        int x,y;
        cin>>x>>y;
        if(!drop){
            if(tab[x] == 1 and tab[y] == 0) { fpos = y; tab[y] = 1 ; tab[x] = 0; }
            else if(tab[x] == 0 and tab[y] == 1) { fpos = x; tab[x] = 1; tab[y] = 0;}
            else if(tab[x] == -1 and tab[y] == 1) {fpos = x; drop = true;}
            else if(tab[x] == 1 and tab[y] == -1) {fpos = y; drop = true;}
        }
    }
    cout<<fpos<<endl;
    return 0;
}