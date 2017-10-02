#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int arr[26];
		int mat[2][n+1];

		for(int i=0 ; i<26 ; i++){
			arr[i]=0;
		}

		string str1;
		string str2;

		cin>>str1;
		cin>>str2;

		for(int i=0 ; i<n ; i++){
			arr[str1[i]-'a']++;
			arr[str2[i]-'a']++;
		}


		int curr = 0;
		for(int i=0 ; i<26 ; i++){
			if(arr[i] % 2 == 0){
				for(int j=0 ; j<arr[i]/2 ; j++){
					mat[0][curr] = mat[1][curr] = i;
					curr++; 
				}
			}
		}

		bool flag = false;

		for(int i=0 ; i<26 ; i++){
			if(arr[i] % 2 == 1){
				if(flag){
					mat[1][curr] = i;
					curr++;
					for(int k=0 ; k<arr[i]/2 ; k++){
						mat[0][curr] = i;
						mat[1][curr] = i;
						curr++;
					}
					flag = false;
				}else{
					for(int k=0 ; k<arr[i]/2 ; k++){
						mat[0][curr] = i;
						mat[1][curr] = i;
						curr++;
					}
					mat[0][curr] = i;
					flag = true;
				}	
			}
		}

		for(int i=0 ; i<2 ; i++){
			for(int j=0 ; j<n ; j++){
				cout<<(char)(mat[i][j]+'a');
			}
			cout<<endl;
		} 
	}

	return 0;
}