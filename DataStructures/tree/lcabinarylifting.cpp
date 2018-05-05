#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define logn 32
//nlogn space for dp
//pa[u][i] represents parent of u at dist of 2^i
int pa[N][32], d[N], k, p, n, q, A, B, C;

vector<int> tree[N];

void dfs(int s,int p,int dis){
	d[s] = dis;
	pa[s][0] = p;
	for(int i = 0; i < tree[s].size(); i++){
		int u = tree[s][i];
		if (u != p) dfs(tree[s][i],s,dis+1);
	}
}

//O(nlogn)
void prep(){
	for(int i = 1; i<=logn ; i++){
		for(int j=1 ; j<=n; j++)    pa[j][i] = pa[pa[j][i - 1]][i - 1];
	}
}

int lca(int x, int y) {
	if (d[x] > d[y]) swap(x, y);
	int h = d[y] - d[x];
    cout<<d[y]<<" "<<d[x]<<endl;
	for (int i=0 ; i<20 ; i++) if (h >> i & 1) y = pa[y][i];
	if (x == y) return x;
	for (int i=19 ; i>=0 ; i--) if (pa[x][i] != pa[y][i]) x = pa[x][i], y = pa[y][i];
	return pa[x][0];
}

int dist(int x, int y) {
	int z = lca(x, y);
	return d[x] + d[y] - 2*d[z];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0 ; i<n-1 ; i++){
        int s,d;
        cin>>s>>d;
        tree[s].push_back(d);
        tree[d].push_back(s);
    }

    dfs(1,-1,0);
    prep();
    cout<<lca(6,4)<<endl;
    return 0;
}