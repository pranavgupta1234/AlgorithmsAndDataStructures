#include <iostream>
#include <vector>
#include <string>
#define endl "\n"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int t;
	cin>>t;

	while(t--){
		string conf;
		cin>>conf;
		int a = 0;
		int b = 0;
		int emp = 0;
		for(int i=0 ; i<conf.length() ; i++){
			if(conf[i] == 'A'){
				a++;
			}else if(conf[i] == 'B'){
				b++;
			}else{
				emp++;
			}
		}

		for(int i=1 ; i<=conf.length()-2 ; i++){
			if(conf[i] == '.'){
				int left = i-1;
				int right = i+1;
				while(left >= 0 and right < conf.length() and (conf[left] == '.' or conf[right] == '.')){
					if(conf[left] == '.'){
						left--;
					}
					if(conf[right] == '.'){
						right++;
					}
				}
				//cout<<conf[left]<<" "<<conf[right]<<endl;
				if(conf[left] == 'A' and conf[right] == 'A'){
					a++;
				}
				if(conf[left] == 'B' and conf[right] == 'B'){
					b++;
				}
			}
		}
		cout<<a<<" "<<b<<endl;
	}


	return 0;
}