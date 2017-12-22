#include <bits/stdc++.h>

using namespace std;

class compare{
    public:
    bool operator() (  pair<int, int> p1,  pair<int, int> p2 ){
        return p1.second > p2.second;
    }
};

int* dist;

void dijkstra(vector<vector<pair<int,int> > >& graph,int s){
    priority_queue<pair<int,int>, vector<pair<int,int> > , compare> q;
    q.push(make_pair(s,0));
    dist[s] = 0;
    while(!q.empty()){
        int v = q.top().first;
        q.pop();
        for(int i=0 ; i<graph[v].size() ; i++){
            if(dist[graph[v][i].first] > dist[v] + graph[v][i].second){
                dist[graph[v][i].first] = dist[v] + graph[v][i].second;
                q.push(graph[v][i]);
            }
        }
    }
    for(int i=1 ; i<graph.size() ; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int> > > graph(n+1,vector<pair<int,int> >(0));
    for(int i=0 ; i<m ; i++){
        int s,d,w;
        cin>>s>>d>>w;
        graph[s].push_back(make_pair(d,w));
        graph[d].push_back(make_pair(s,w));
    }

    dist = new int[n+1];                                      //final distances will be stored here
    for(int i=0 ; i<=n ; i++){
        dist[i] = INT_MAX-100;
    }

    dijkstra(graph,1);

    return 0;
}   