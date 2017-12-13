#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		bool flag = false;
		for(int a=0 ; a<=x/3 ; a++){
			for(int b=0 ; b<=x/7 ; b++){
				if(3*a + 7*b == x){
					flag = true;
					break;
				}
			}
		}
		cout<<(flag ? "YES" : "NO")<<endl;
	}
}