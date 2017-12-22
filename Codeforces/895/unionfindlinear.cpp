#include <iostream>
#include <cstring>

using namespace std;

int n;
int *parent;

//returns representative element of set, note that rep has always a value of i in parent[i]
int find(int a){
	if(parent[a] == a){
		return a;
	}else{
		return find(parent[a]);
	}
}

void Union(int a,int b){
	int x = find(a);
	int y = find(b);
	parent[y] = x; 
}

bool isSame(int a,int b){
	return find(a) == find(b);
}

void print(){
	for(int i=0; i<n ; i++){
		cout<<parent[i]<<" ";
	}
	cout<<endl;
}

int main(){
	cin>>n;
	parent = new int[n];
	//0 to n-1 each in diff set 
	for(int i=0 ; i<n ; i++){
		parent[i] = i;
	}
	Union(0,1);
	cout<<isSame(0,1)<<endl;
	Union(1,2);
	cout<<isSame(1,2)<<endl;
	Union(2,3);
	cout<<isSame(0,1)<<endl;
	Union(3,4);
	cout<<isSame(3,4)<<endl;
	cout<<isSame(0,4)<<endl;

	//note that here worst case complexity is linear as tree may be skewed and
	//to come from leaf to root one has to
	return 0;
}