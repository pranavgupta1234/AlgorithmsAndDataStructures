#include <iostream>
#include <vector>

#define endl "\n"
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	cin>>n>>x;
	bool flag = true;
	vector<int> encoding(n,0);
	long sum = 0;
	for(int i=0 ; i<n ; i++){
		cin>>encoding[i];
		sum += encoding[i];
	}

	if(sum + encoding.size()-1 != x){
		flag = false;
	}
	cout<<(flag ? "YES" : "NO")<<endl;
	return 0;
}