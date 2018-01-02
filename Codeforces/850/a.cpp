#include <bits/stdc++.h>

#define PI 3.14159265

using namespace std;

class point{
public:
	int a,b,c,d,e;
	point(int a,int b,int c, int d,int e){
		this -> a = a;
		this -> b = b;
		this -> c = c;
		this -> d = d;
		this -> e = e;
	}
};

inline long long dotprod(point x,point y){
	return x.a*y.a + x.b*y.b + x.c*y.c + x.d*y.d + x.e*y.e; 
}

inline point vec(point x,point y){
	return point(y.a-x.a,y.b-x.b,y.c-x.c,y.d-x.d,y.e-x.e); 
}

inline long long mod(point x,point y){
	return sqrt(pow(y.a-x.a,2)+pow(y.b-x.b,2)+pow(y.c-x.c,2)+pow(y.d-x.d,2)+pow(y.e-x.e,2));
}

//angle between ab and ac
inline bool isacute(point a,point b,point c){
	return (dotprod(vec(a,b),vec(b,c))*1.0 / mod(a,b)*mod(b,c) )* (180.0)/PI < 90.0;
}


int main(){

	int n;
	cin>>n;
	vector<point> points;
	
	for(int i=0 ; i<n ; i++){
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		points.push_back(point(a,b,c,d,e));
	}

	int votes = 0;	
	vector<pair<int,point> > good;

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			for(int k=0 ; k<n ;k++){
				if(i != j and i != k){
					if(!isacute(points[i],points[j],points[k])){
						good.push_back(make_pair(i+1,points[i]));
					}
				}
			}
		}
	}

	cout<<points.size()<<endl;

	for(int i=0 ; i<good.size() ; i++){
		cout<<good[i].first<<endl;
	}

}