#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,k;
ll gm[330][330];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++) cin>>gm[i][j];
    cin>>k;
    for(int i=0 ; i<k ; i++){
        int s,d,w;
        cin>>s>>d>>w;
        if(w < gm[s][d]){
            gm[s][d] = w;
            gm[d][s] = w;
            for(int j=1 ; j<=n ; j++){
                for(int k=1 ; k<=n ; k++){
                    if(gm[j][s] + w + gm[d][k] < gm[j][k]){
                        gm[j][k] = gm[j][s] + w + gm[d][k];
                    } 
                    if(gm[j][d] + w + gm[s][k] < gm[j][k]){
                        gm[j][k] = gm[j][d] + w + gm[s][k];
                    }
                }
            }
        }
        ll cost = 0;
        for(int x=1 ; x<=n ; x++){
            for(int y=1 ; y<=n ; y++){
                cost += gm[x][y];
            }
        }
        cout<<cost/2<<" ";
    }    
    cout<<endl;

    return 0;
}