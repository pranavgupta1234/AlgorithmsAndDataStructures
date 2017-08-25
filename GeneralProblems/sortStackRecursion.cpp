#include <iostream>
#include <stack>

using namespace std;

void sortedInsert(stack<int>& stk,int val){

	if(stk.empty() or stk.top() < val){
		stk.push(val);
	}else{	
		int temp = stk.top();
		stk.pop();
		sortedInsert(stk,val);
		stk.push(temp);
	}
}

void funcCall(stack<int>& stk){

	if(!stk.empty()){

		int temp = stk.top();
		stk.pop();
		funcCall(stk);
		sortedInsert(stk,temp);
	}

}

int main(){
	
	stack<int> stk;

	stk.push(45);
	stk.push(67);
	stk.push(3);
	stk.push(456);
	stk.push(435);
	stk.push(34);
	stk.push(6789);

	funcCall(stk);

	while(!stk.empty()){
		cout<<stk.top()<<" ";
		stk.pop();
	}

	cout<<endl;

	return 0;
}