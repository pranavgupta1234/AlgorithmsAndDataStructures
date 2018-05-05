#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int> > seg;
        for(int i=1 ; i<=n ; i++){
            int s,e;
            cin>>s>>e;
            seg.push_back(make_pair(s,e));
        } 
        int q;
        cin>>q;
        while(q--){
            int m;
            cin>>m;
            vector<int> pts(m,0);
            for(int i=0 ; i<m ; i++)    cin>>pts[i];
            int no = 0;
            sort(pts.begin(),pts.end());
            for(int i=0 ; i<seg.size() ; i++){
                int nop = 0;
                for(int j=seg[i].first ; j<=seg[i].second ; j++) if(binary_search(pts.begin(),pts.end(),j)) nop++;
                if(nop&1) no++;
            }
            cout<<no<<endl;
        }
    }
    return 0;
}