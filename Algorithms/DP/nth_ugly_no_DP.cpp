#include <bits/stdc++.h>
using namespace std;
int getNthUglyNo(int);
int main(){
    cout<<getNthUglyNo(150)<<endl;
	return 0;
}
int getNthUglyNo(int n){
	int ugly[n];
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    int nextMultipleOf2 = 2;
    int nextMultipleOf3 = 3;
    int nextMultipleOf5 = 5;
    int next_ugly_number=1;
   
    ugly[0] = 1;

    for(int i=1;i<n;i++){
        next_ugly_number = min(nextMultipleOf2,min(nextMultipleOf3,nextMultipleOf5));
        ugly[i]=next_ugly_number;
        if(next_ugly_number == nextMultipleOf2){
        	i2+=1;
        	nextMultipleOf2 = ugly[i2]*2;
        }
        if(next_ugly_number == nextMultipleOf3){
        	i3+=1;
        	nextMultipleOf3 = ugly[i3]*3;
        }
        if(next_ugly_number == nextMultipleOf5){
        	i5+=1;
        	nextMultipleOf5 = ugly[i5]*5;
        }
        //cout<<next_ugly_number<<endl;
    }
    return next_ugly_number;
}