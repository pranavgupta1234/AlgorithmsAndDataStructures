#include <iostream>
#include "queue.hpp"
using namespace std;

int main(int argc,char *argv[]){

	q::queue<int> test_queue;

	int to_do;
	int temp;
	bool done = true;

	cout<<"Please select what you want to do :"<<endl;
	cout<<"1. Push"<<endl;
	cout<<"2. Pop"<<endl;
	cout<<"3. Front"<<endl;
	cout<<"4. Size?"<<endl;
	cout<<"5. is Empty?"<<endl;
	cout<<"6. Print Queue"<<endl;
	cout<<"Press any other key to exit"<<endl;

	while(done){

		cin>>to_do;

		switch(to_do){

		case 1:
			cout<<"Enter value to be pushed ?"<<endl;
			cin>>temp;
			test_queue.push(temp);
			cout<<"Choose Again ?"<<endl;
			break;
		case 2:
		 	cout<<"Popped element is "<<test_queue.pop()<<endl;
		 	cout<<"Choose Again ?"<<endl;
		 	break;
		case 3:
			cout<<"Top element in the stack is :: "<<test_queue.front()<<endl;
		 	cout<<"Choose Again ?"<<endl;
		 	break;
		case 4:
			cout<<"Size is :: "<<test_queue.size()<<endl;
			cout<<"Choose Again ?"<<endl;
			break;
		case 5:
			(test_queue.empty()!=0 ? cout<<"Yes"<<endl : cout<<"No"<<endl);
			cout<<"Choose Again ?"<<endl;
			break;
		case 6:
		  	cout<<"The queue is :: ";
		  	test_queue.print_queue();
		  	cout<<"Choose Again ?"<<endl;
		  	break;
		default :
			done = false;
		}	
	}

	return 0;
}