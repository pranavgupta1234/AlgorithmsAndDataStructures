#include <iostream>
#include "stack.hpp"
using namespace std;

int main(int argc,char *argv[]){

	stk::stack<int> test_stack;

	int to_do;
	int temp;
	bool done = true;

	cout<<"Please select what you want to do :"<<endl;
	cout<<"1. Push"<<endl;
	cout<<"2. Pop"<<endl;
	cout<<"3. Top"<<endl;
	cout<<"4. Size?"<<endl;
	cout<<"5. is Empty?"<<endl;
	cout<<"6. Print Stack"<<endl;
	cout<<"Press any other key to exit"<<endl;

	while(done){

		cin>>to_do;

		switch(to_do){

		case 1:
			cout<<"Enter value to be pushed ?"<<endl;
			cin>>temp;
			test_stack.push(temp);
			cout<<"Choose Again ?"<<endl;
			break;
		case 2:
		 	cout<<"Popped element is "<<test_stack.pop()<<endl;
		 	cout<<"Choose Again ?"<<endl;
		 	break;
		case 3:
			cout<<"Top element in the stack is :: "<<test_stack.top()<<endl;
		 	cout<<"Choose Again ?"<<endl;
		 	break;
		case 4:
			cout<<"Size is :: "<<test_stack.size()<<endl;
			cout<<"Choose Again ?"<<endl;
			break;
		case 5:
			(test_stack.empty()!=0 ? cout<<"Yes"<<endl : cout<<"No"<<endl);
			cout<<"Choose Again ?"<<endl;
			break;
		case 6:
		  	cout<<"The stack is :: ";
		  	test_stack.print_stack();
		  	cout<<"Choose Again ?"<<endl;
		  	break;
		default :
			done = false;
		}	
	}

	return 0;
}