#include <iostream>
#include <vector>

using namespace std;

struct point{
	int x;
	int y;
};

bool overlap(point& l1,point& r1,point& l2,point& r2);

int main(){
	
	point l1 = { 0,10};
	point r1 = { 10,0};
	point l2 = {5 , 5};
	point r2 = { 15, 0};

	if(overlap(l1,r1,l2,r2)){
		cout<<"Overlap"<<endl;
	}else{
		cout<<"No Overlap"<<endl;
	}

	return 0;
}

bool overlap(point& l1,point& r1,point& l2,point& r2){

	if(l1.x > r2.x or l2.x > r1.x){
		return false;
	}

	if(l1.y < r2.y or r1.y > l2.y){
		return false;
	}

	return true;
}