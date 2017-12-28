#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	int v1,v2,v3,vm;
	cin>>v1>>v2>>v3>>vm;
	int c1,c2,c3;
	bool flag = false;
	for(int i=v1 ; i<= 2*v1 ; i++){
		for(int j=v2 ; j<=2*v2 ; j++){
			for(int k=v3 ; k<=2*v3 ; k++){
				if(vm <= i and vm <= j and  vm <= k and k<=2*vm and 2*vm < i and 2*vm < j and i > j and j>k){
					flag = true;
					c1 = i;
					c2 = j;
					c3 = k;
					break;
				}
			}
			if(flag){
				break;
			}
		}
		if(flag){
			break;
		}
	}

	if(flag){
		cout<<c1<<endl;
		cout<<c2<<endl;
		cout<<c3<<endl;
	}else{
		cout<<"-1"<<endl;
	}

	return 0;
}