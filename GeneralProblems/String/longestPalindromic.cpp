#include <iostream>
#include <string>

using namespace std;

string longestPalindromic(string& str){
	int maxLen = 1;
	int startIndex = 0;
	int len = str.length();
	int low,high;
	for(int i=1 ; i<len ; i++){
		low = i-1;
		high = i;
		while(low >= 0 and high < len and str[low] == str[high]){
			if(high - low + 1 > maxLen){
				startIndex = low;
				maxLen = high - low + 1;
			}
			low--;
			high++;
		}
		low = i-1;
		high = i+1;
		while(low>=0 and high < len and str[low] == str[high]){
			if(high - low + 1 > maxLen){
				startIndex = low;
				maxLen = high - low + 1;
			}
			low--;
			high++;
		}
	}
	string longest;
	for(int i=startIndex ; i< startIndex + maxLen ; i++){
		longest.push_back(str[i]);
	}
	return longest;
}

int main(){
	
	string str;
	cin>>str;

	cout<<longestPalindromic(str);
	cout<<endl;

	return 0;
}