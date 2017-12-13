#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int mindiff = 360;
	int part1 = 0;
	int part2 = 0;
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}
	for(int i=0 ; i<n ; i++){
		part1 = arr[i];
		int totalPieces = n-1;
		int j = i+1;
		mindiff = min(abs(2*part1-360),mindiff);
		while(totalPieces){
			part1 += arr[j%n];
			part2 = 360 - part1;
			mindiff = min(abs(part1-part2),mindiff);
			j++;
			totalPieces--;
		}
	}
	cout<<mindiff<<endl;
	return 0;
}