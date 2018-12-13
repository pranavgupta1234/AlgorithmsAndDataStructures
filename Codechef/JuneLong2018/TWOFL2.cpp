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

ll bfs(int** mat,int i,int j,int a,int b,vector<vector<set<ll> > >& done){
    bool** visited = new bool* [n];
    for(int i=0 ; i<n ; i++) visited[i] = new bool[m];
    for(int i=0 ; i<n ; i++) for(int j=0 ; j<m ; j++) visited[i][j] = false;
	Node source(i,j,0);
	queue<Node> q;
	q.push(source);
	ll ar = 0;
	visited[i][j] = true;
    done[i][j].insert(a);
    done[i][j].insert(b);
	while(!q.empty()){
		Node visit = q.front();
		q.pop();
		ar++;
		//move up
		if(visit.row - 1 >= 0 and visited[visit.row-1][visit.col] == false 
			and (mat[visit.row-1][visit.col] == a or mat[visit.row-1][visit.col] == b) ){
			visited[visit.row-1][visit.col] = true;
            done[visit.row-1][visit.col].insert(a);
            done[visit.row-1][visit.col].insert(b);
			q.push(Node(visit.row-1,visit.col,visit.dist+1));
		}
		//move down
		if(visit.row + 1 < n  and visited[visit.row+1][visit.col] == false and 
			(mat[visit.row+1][visit.col] == a or mat[visit.row+1][visit.col] == b) ){
			visited[visit.row+1][visit.col] = true;
            done[visit.row+1][visit.col].insert(a);
            done[visit.row+1][visit.col].insert(b);
			q.push(Node(visit.row+1,visit.col,visit.dist+1));
		}

		//move right
		if(visit.col + 1 < m and visited[visit.row][visit.col + 1] == false
			and (mat[visit.row][visit.col + 1] == a or mat[visit.row][visit.col + 1] == b)){
			visited[visit.row][visit.col+1] = true;
            done[visit.row][visit.col+1].insert(a);
            done[visit.row][visit.col+1].insert(b);
			q.push(Node(visit.row,visit.col+1,visit.dist+1));
		}
		//move left
		if(visit.col - 1 >= 0 and visited[visit.row][visit.col-1] == false and 
			(mat[visit.row][visit.col-1] == a or mat[visit.row][visit.col-1] == b)){
			visited[visit.row][visit.col-1] = true;
            done[visit.row][visit.col-1].insert(a);
            done[visit.row][visit.col-1].insert(b);
			q.push(Node(visit.row,visit.col-1,visit.dist+1));
		}
	}
	
	return ar;
}

ll bfs_area(int** mat,int i,int j,int a,bool** mark,vector<vector<set<ll> > >& done){
	bool** visited = new bool* [n];
    for(int i=0 ; i<n ; i++) visited[i] = new bool[m];
    for(int i=0 ; i<n ; i++) for(int j=0 ; j<m ; j++) visited[i][j] = false;
    Node source(i,j,0);
	queue<Node> q;
	q.push(source);
	visited[i][j] = true;
    set<ll> adj;
	while(!q.empty()){
		Node visit = q.front();
		q.pop();
		//move up
        if(visit.row - 1 >= 0) adj.insert(mat[visit.row-1][visit.col]);
		if(visit.row - 1 >= 0 and visited[visit.row-1][visit.col] == false and mat[visit.row-1][visit.col] == a){
			visited[visit.row-1][visit.col] = true;
            mark[visit.row-1][visit.col] = true;
			q.push(Node(visit.row-1,visit.col,visit.dist+1));
		}
		//move down
        if(visit.row + 1 < n) adj.insert(mat[visit.row+1][visit.col]);
		if(visit.row + 1 < n  and visited[visit.row+1][visit.col] == false and mat[visit.row+1][visit.col] == a){
			visited[visit.row+1][visit.col] = true;
            mark[visit.row+1][visit.col] = true;
			q.push(Node(visit.row+1,visit.col,visit.dist+1));
		}
		//move right
        if(visit.col + 1 < m) adj.insert(mat[visit.row][visit.col + 1]);
		if(visit.col + 1 < m and visited[visit.row][visit.col + 1] == false and mat[visit.row][visit.col + 1] == a){
			visited[visit.row][visit.col+1] = true;
            mark[visit.row][visit.col+1] = true;
			q.push(Node(visit.row,visit.col+1,visit.dist+1));
		}
		//move left
        if(visit.col - 1 >= 0) adj.insert(mat[visit.row][visit.col-1]);
		if(visit.col - 1 >= 0 and visited[visit.row][visit.col-1] == false and mat[visit.row][visit.col-1] == a){
			visited[visit.row][visit.col-1] = true;
            mark[visit.row][visit.col-1] = true;
			q.push(Node(visit.row,visit.col-1,visit.dist+1));
		}
	}

    ll mx = 1;  
    for(auto v : adj){
        if(done[i][j].find(v) == done[i][j].end()){
            mx = max(mx,bfs(mat,i,j,v,a,done));
            //if((i==0 and j==1) or (i==4 and j==4))
            cout<<i<<" "<<j<<" "<<v<<endl;
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
		}
	}
    ll area = 1;
    bool** mark = new bool*[n];
    for(int i=0 ; i<n ; i++) mark[i] = new bool[m];
    for(int i=0 ; i<n ; i++) for(int j=0 ; j<m ; j++) mark[i][j] = false;   
    vector<vector<set<ll> > > done(n,vector<set<ll> >(m,set<ll>()));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(mark[i][j] == false){
                //int val = bfs_area(matrix,i,j,matrix[i][j]);
                area = max(area,bfs_area(matrix,i,j,matrix[i][j],mark,done));
                //cout<<i<<" "<<j<<" "<<val<<endl;
                //exit(0);
            }
        }
    }
	cout<<area<<endl;
    return 0;
} 
