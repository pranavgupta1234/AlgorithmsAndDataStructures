#include <iostream>                                                                                                   
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

struct num {
	int val, count, index;
	num(int v, int c, int i) {
		val=v;
		count=c;
		index=i;
	}
};

bool operator < (num a, num b) {
	if(a.count==b.count) {
		return a.index<b.index;
	}
	else return a.count>b.count;
}

int main () {
	int n,c;
        //freopen("input.txt","r",stdin);
	map <int , pair<int,int> > m;
	scanf("%d %d",&n,&c);
	int temp;
	for(int i=0;i<n;i++) {
		scanf("%d",&temp);
		map <int, pair <int,int> >::iterator it = m.find(temp);
		if(it==m.end()) {
			m[temp]=make_pair(i,1);
		}
		else {
			it->second.second++;
		}
	}
	vector <num> v;
	for(map< int,pair<int,int> >::iterator it=m.begin();it!=m.end();it++) {
//                cout<<it->first<<"  "<<it->second.first<<" "<<it->second.second<<endl;
		v.push_back(num(it->first,it->second.second,it->second.first));
	}
	sort(v.begin(), v.end());
	for(vector <num>::iterator it=v.begin();it!=v.end();it++) {
		for(int i=0;i<it->count;i++) {
			printf("%d ",it->val);
		}
	}
	printf("\n");
	return 0;
}  