#include <iostream>
#include <vector>
#include <istream>
#include <ostream>
#include <cstring>

using namespace std;

int main(){
	string result;
	/*fgets()  reads in at most one less than size characters from stream and
       stores them into the buffer pointed to by s.  Reading  stops  after  an
       EOF  or a newline.  If a newline is read, it is stored into the buffer.
       A terminating null byte ('\0') is stored after the  last  character  in
       the buffer.
       Hence instead of 20, 21 is used as we need 20 for data
    */    
    //fgets(result,21,stdin) != NULL and result[0] != '\n'
	while(getline(cin,result)){
		char chef[10];
		char oppnt[10];
		int max_poss_chef = 5;									//Denotes max possible score one can obtain at a particular stage
		int max_poss_oppnt = 5;
		int curr_chef_score = 0;
		int curr_oppnt_score = 0;
		bool before5 = false;
		int sufficient_goals = 0;
		for(int i=0,j=0 ; i<20 ; i+=2,j++){
			chef[j] = result[i];
		}
		for(int i=1,j=0 ; i<20 ; i+=2,j++){
			oppnt[j] = result[i];
		}
		for(int i=0 ; i<5 ; i++){
			if(chef[i] == '1'){
				curr_chef_score++;
			}else{
				max_poss_chef--;
			}
			sufficient_goals++;
			if(curr_chef_score > max_poss_oppnt or curr_oppnt_score > max_poss_chef){
				before5 = true;
				break;
			}
			if(oppnt[i] == '1'){
				curr_oppnt_score++;
			}else{
				max_poss_oppnt--;
			}
			sufficient_goals++;
			if(curr_chef_score > max_poss_oppnt or curr_oppnt_score > max_poss_chef){
				before5 = true;
				break;
			}
		}
		if(before5){
			if(curr_chef_score > max_poss_oppnt){
				cout<<"TEAM-A"<<" "<<sufficient_goals<<endl;
			}else if(curr_oppnt_score > max_poss_chef){
				cout<<"TEAM-B"<<" "<<sufficient_goals<<endl;
			}
		}else{
			int winner = 2;
			for(int i=5 ; i<10 ; i++){
				if(chef[i] == '1' and oppnt[i] == '0'){
					sufficient_goals = 2*(i+1);
					winner = 0;
					break;
				}else if(chef[i] == '0' and oppnt[i] == '1'){
					winner = 1;
					sufficient_goals = 2*(i+1);
					break;
				}else{
					continue;
				}
			}
			if(winner == 0){
				cout<<"TEAM-A"<<" "<<sufficient_goals<<endl;
			}else if(winner == 1){
				cout<<"TEAM-B"<<" "<<sufficient_goals<<endl;
			}else{
				cout<<"TIE"<<endl;
			}
		}
	}
	return 0;
}