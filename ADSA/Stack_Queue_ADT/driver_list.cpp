#include <iostream>
#include "list.hpp"
using namespace std;

int main(int argc,char *argv[]){

	ll::list<int> test_list;
	ll::list<int> to_append;

	int to_do;
	int temp;
	bool done = true;

	cout<<"Please select what you want to do :"<<endl;
	cout<<"1. Insert At End"<<endl;
	cout<<"2. Length of list"<<endl;
	cout<<"3. Is list Empty?"<<endl;
	cout<<"4. Insert At Beginning"<<endl;
	cout<<"5. Remove first occurence of a specific value"<<endl;
	cout<<"6. Append list at end of initial list"<<endl;
	cout<<"7. Print List"<<endl;
	cout<<"8. Show first element in list"<<endl;
	cout<<"Press any other key to exit"<<endl;

	while(done){

		cin>>to_do;

		switch(to_do){

		case 1:
			cout<<"Enter value to be inserted ?"<<endl;
			cin>>temp;
			test_list.append(temp);
			cout<<"Choose Again ?"<<endl;
			break;
		case 2:
		 	cout<<"Length of list is "<<test_list.length()<<endl;
		 	cout<<"Choose Again ?"<<endl;
		 	break;
		case 3:
			(test_list.empty()!=0 ? cout<<"Yes"<<endl : cout<<"No"<<endl);
			cout<<"Choose Again ?"<<endl;
			break;
		case 4:
			cout<<"Please enter value to insert"<<endl;
			cin>>temp;
			test_list.insert(temp);
			cout<<"Choose Again ?"<<endl;
			break;
		case 5:
			cout<<"Enter the element to be removed"<<endl;
			cin>>temp;
			test_list.remove(temp);
			cout<<"Choose Again ?"<<endl;
			break;
		case 6:
			int size;
			cout<<"Enter the size of the list to be appended "<<endl;
			cin>>size;
			cout<<"Enter the list to be appended :"<<endl;
			for(int i=0;i<size;i++){
				cin>>temp;
				to_append.append(temp);
			}
			test_list.append(to_append);
			cout<<"Choose Again ?"<<endl;
			break;
		case 7:
		  	cout<<"The list is :: ";
		  	test_list.printList();
		  	cout<<"Choose Again ?"<<endl;
		  	break;
		case 8:
			cout<<"The first element in the list is :: "<<test_list.top_element()<<endl;
			cout<<"Choose Again ?"<<endl;
			break;
		default :
			done = false;
		}	
	}
	return 0;
}