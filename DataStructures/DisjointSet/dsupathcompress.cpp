#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct subset{
	int parent;
	int rank;
};	

int n;
subset* set;

/*					***************Path Compression*******************
The second optimization to naive method is Path Compression. The idea is to flatten the tree when find() is called.
When find() is called for an element x, root of the tree is returned. The find() operation traverses up from x to 
find root. The idea of path compression is to make the found root as parent of x so that we don’t have to traverse 
all intermediate nodes again. If x is root of a subtree, then path (to root) from all nodes under x also compresses.
*/

int find(int x){	
	if(set[x].parent == x){
		return set[x].parent;
	}else{
		set[x].parent = find(set[x].parent);				//path compression tries to flatten the tree
	}
}	


/*    ************************Union By Rank**************************
The above operations can be optimized to O(Log n) in worst case. The idea is to always attach smaller depth tree
under the root of the deeper tree. This technique is called union by rank. The term rank is preferred instead of
height because if path compression technique is used, then rank is not always equal to height. Also, size 
(in place of height) of trees can also be used as rank. Using size as rank also yields worst case time complexity
as O(Logn)
*/
void Union(int a,int b){
	int xroot = find(a);
	int yroot = find(b);

	if(set[xroot].rank < set[yroot].rank){
		set[xroot].parent = yroot; 
		set[xroot].rank++;
	}else if(set[xroot].rank > set[yroot].rank){
		set[yroot].rank = xroot;
		set[yroot].rank++;
	}else{
		set[xroot].parent = yroot;
		set[xroot].rank++;
	}
}

bool same(int a,int b){
	return find(a) == find(b);
}

int main(){
	cin>>n;
	set = new subset[n];
	for(int i=0 ; i<n ; i++){
		set[i].parent = i;
		set[i].rank = 0;
	}

	cout<<same(0,1)<<endl;
	Union(0,1);
	cout<<same(0,1)<<endl;
	Union(1,2);
	cout<<same(0,2)<<endl;
	cout<<same(1,2)<<endl;
	Union(2,3);
	Union(3,4);
	cout<<same(0,4)<<endl;		
	cout<<same(0,1)<<endl;

	return 0;
}