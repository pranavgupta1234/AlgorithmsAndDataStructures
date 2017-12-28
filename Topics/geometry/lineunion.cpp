#include <iostream>
#include <vector>
#include <algorithm>

#define uint unsigned

using namespace std;

unsigned segments_union_measure(const vector <pair <int, int> > & a){
	unsigned n = a.size ();
	vector <pair <int, bool> > x(n*2);
	for(uint i = 0; i <n; i ++){
		x [i*2] = make_pair(a[i].first, false);
		x [i*2+1] = make_pair(a[i].second, true);
	}

	sort(x.begin(),x.end());

	unsigned result = 0;
	unsigned c = 0;
	for(unsigned i = 0; i<n*2; i++){
		if(c){
			result += unsigned(x[i].first - x[i-1].first);
		}
		x[i].second ? c-- : c++ ;
	}
	return result;
}

int main(){
	
	int n;
	cin>>n;
	vector<pair<int,int> > points;

	for(int i=0 ; i<n ; i++){	
		int s,e;
		cin>>s>>e;
		points.push_back(make_pair(s,e));
	}

	cout<<segments_union_measure(points)<<endl;
	return 0;
}