#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double dbl;
typedef vector<int> vi;
typedef vector<ll> vii;
typedef pair<int,int> pii;
typedef tree<ll, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
const ll mod=1000000007;
int n,m;


class Node{
public:
	int row;						//row	
	int col;						//col
	int dist;

	Node(int row,int col,int z){
		this -> row = row;
		this -> col = col;
		this -> dist = z;
	}
};

ll gcd(ll a,ll b) { return  b ? gcd(b,a%b) : a ; }
ll pwrmod(ll a,ll b) {
    ll res=1;
    a %= mod;
    assert(b>=0);
    for( ; b ; b>>=1) {
        if(b&1) res = res*a%mod;
        a = a*a%mod;
    }
    return res;
}
ll pwr(ll a,ll b){
    ll res=1;
    assert(b >= 0);
    for( ; b ; b>>=1) {
        if(b&1) res = res*a;
        a = a*a;
    }
    return res;
}
ll eea(ll a,ll b,ll &x,ll &y) {
    if(a == 0) {
        x=0 ; y=1 ;
        return b;
    }
    ll x1, y1;
    ll d = eea(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return d;
}

ll bsearch(ll a[],ll val,ll l,ll h){
    while(l<=h){
        ll mid = l + (h-l)/2;
        if(a[mid] == val) return mid;
        else if(a[mid]<val) l = mid+1;
        else h = mid-1;
    }
    return -1;
}

/*
Given a matrix of N*M order. Find the shortest distance from a source cell to a destination cell, traversing through 
limited cells only. Also you can move only up, down, left and right. If found output the distance else -1.
*/

int bfs(int** mat,int i,int j,bool** visited,int a,int b){
	Node source(i,j,0);
	queue<Node> q;
	q.push(source);
	ll ar = 0;
	visited[i][j] = true;
	while(!q.empty()){
		Node visit = q.front();
		q.pop();
		ar++;
		//move up
		if(visit.row - 1 >= 0 and visited[visit.row-1][visit.col] == false 
			and (mat[visit.row-1][visit.col] == a or mat[visit.row-1][visit.col] == b) ){
			visited[visit.row-1][visit.col] = true;
			q.push(Node(visit.row-1,visit.col,visit.dist+1));
		}
		//move down
		if(visit.row + 1 < n  and visited[visit.row+1][visit.col] == false and 
			(mat[visit.row+1][visit.col] == a or mat[visit.row+1][visit.col] == b) ){
			visited[visit.row+1][visit.col] = true;
			q.push(Node(visit.row+1,visit.col,visit.dist+1));
		}

		//move right
		if(visit.col + 1 < m and visited[visit.row][visit.col + 1] == false
			and (mat[visit.row][visit.col + 1] == a or mat[visit.row][visit.col + 1] == b)){
			visited[visit.row][visit.col+1] = true;
			q.push(Node(visit.row,visit.col+1,visit.dist+1));
		}
		//move left
		if(visit.col - 1 >= 0 and visited[visit.row][visit.col-1] == false and 
			(mat[visit.row][visit.col-1] == a or mat[visit.row][visit.col-1] == b)){
			visited[visit.row][visit.col-1] = true;
			q.push(Node(visit.row,visit.col-1,visit.dist+1));
		}
	}
	
	return ar;
}

ll max_area(int a,int b,int** mat){
	bool** vis = new bool*[n];
	for(int i=0 ; i<n ; i++) vis[i] = new bool[m];
	for(int i=0 ; i<n ; i++) for(int j=0 ; j<m ; j++) vis[i][j] = false;
    ll mx = 1;
	for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if((mat[i][j] == a or mat[i][j] == b) and vis[i][j] == false){
				ll v = bfs(mat,i,j,vis,a,b);
				//cout<<i<<" "<<j<<" "<<v<<endl;
				mx = max(mx,v);
            }
        }
    }
	return mx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>m;
    set<int> s;
	int** matrix = new int*[m];
	for(int i=0 ; i<n ; i++){
		matrix[i] = new int[m];
	}
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cin>>matrix[i][j];
            s.insert(matrix[i][j]);
		}
	}
    vector<int> uniq(s.begin(),s.end());
    ll area = 1;
    for(int i=0 ; i<uniq.size() ; i++){
        for(int j=i ; j<uniq.size() ; j++){
			//int val = max_area(uniq[i],uniq[j],matrix);
            area = max(area,max_area(uniq[i],uniq[j],matrix));
			//cout<<uniq[i]<<" "<<uniq[j]<<" "<<val<<endl;
			//exit(0);
        }
    }
	cout<<area<<endl;
    return 0;
} 
