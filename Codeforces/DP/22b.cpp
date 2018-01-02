#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	char matrix[n][m];

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cin>>matrix[i][j];
		}
	}

	int m_peri = 1;

	for(int x1=0 ; x1<m ; x1++){
		for(int y1=0 ; y1<n ; y1++){
			for(int x2=x1 ; x2<m ; x2++){
				for(int y2=y1 ; y2<n ; y2++){
					bool flag = true;
					for(int i=y1 ; i<=y2 ; i++){
						for(int j=x1 ; j<=x2 ; j++){
							if(matrix[i][j] == '1'){
								flag = false;
								break;
							}
						}
						if(!flag){
							break;
						}
					}
					if(flag){		
						m_peri = max(m_peri,2*((x2-x1+1)+(y2-y1+1)));
					}
				}
			}
		}
	}

	cout<<m_peri<<endl;



	return 0;
}