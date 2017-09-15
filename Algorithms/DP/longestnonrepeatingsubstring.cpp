#include <iostream>
#include <string>

using namespace std;

#define chars 256

int longestSubstring(string str){

	int size = str.length();
	int max_len = 1;
	int cur_max = 1;
	int prev_index;
	int* visited = new int[chars];

	for(int i=0 ; i<chars ; i++){
		visited[i] = -1;
	}

	visited[str[0]] = 0;

	for(int i=1 ; i<str.size() ; i++){

		prev_index = visited[str[i]];

		if(prev_index == -1 or i - cur_max > prev_index){
			cur_max++;
		}else{
			if(cur_max > max_len){
				max_len = cur_max;
			}

			cur_max = i - prev_index;
		}
		visited[str[i]] = i;
	}

	return max_len;

}

int main(){
	
	string s;
	cin>>s;

	cout<<longestSubstring(s)<<endl;

	return 0;
}