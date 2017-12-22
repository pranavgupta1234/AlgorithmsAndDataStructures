#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class edge{
public:
	int s;
	int d;
	int w;

	edge(int s,int d,int w){
		this -> s = s;
		this -> d = d;
		this -> w = w;
	}
};

class subset{
public:
	int parent;
	int rank;
};

int compare(edge a,edge b){
	return a.w < b.w;
}

//union by rank and path compression
int find(subset vertices[],int x){
	if(vertices[x].parent  == x){
		return x;
	}else{
    	vertices[x].parent = find(vertices,vertices[x].parent);			//path compression step 
    }
}

void Union(subset vertices[],int x,int y){
	int xroot = find(vertices,x);
	int yroot = find(vertices,y);
	if(vertices[xroot].rank < vertices[yroot].rank){
		vertices[xroot].parent = yroot;
		vertices[xroot].rank++;
	}else if(vertices[xroot].rank > vertices[yroot].rank){
		vertices[yroot].parent = xroot;
		vertices[yroot].rank++;
	}else{
		vertices[yroot].parent = xroot;
		vertices[yroot].rank++;
	}
}

bool issame(subset vertices[],int x,int y){
	return find(vertices,x) == find(vertices,y);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<edge> edges;	
		subset vertices[n+1];
		vector<edge> mst;
		for(int i=1 ; i<=n ; i++){
			vertices[i].parent = i;
			vertices[i].rank = 0;
		}
		for(int i=0 ; i<m ; i++){
			int s,d,w;
			cin>>s>>d>>w;
			edges.push_back(edge(s,d,w));
		}
		sort(edges.begin(),edges.end(),compare);

		int total = 0;
		int costMST = 0;
		for(int i=0 ; i<edges.size() ; i++){
			if(total == n-1){
				break;
			}
			if(!issame(vertices,edges[i].s,edges[i].d)){
				mst.push_back(edges[i]);
				Union(vertices,edges[i].s,edges[i].d);
				costMST += edges[i].w;
				total++;
			}
		}

		for(int i=0 ; i<mst.size() ; i++){
			cout<<mst[i].s<<" "<<mst[i].d<<" "<<mst[i].w<<endl;
		}
	}
    //cout<<costMST<<endl;
	return 0;
} 