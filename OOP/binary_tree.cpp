#include <iostream>
#include <vector>
using namespace std;

/* When a C++ object is created, two events occur:
1) Storage is allocated for the object.
2) The constructor is called to initialize that storage.
step one may occur from static , stack or heap memory 
cpp enforces the execution of constructor for initialization after storage is granted for object. 
*/
class treeNode{
private:
	
	int value;
	treeNode* left;
	treeNode* right;

public:

	treeNode* newNode(int value);

	int getValue();

	int getValue(treeNode*);

	void setvalue(int value);

};

treeNode* treeNode :: newNode(int value){

	treeNode* newNode = new treeNode();
	newNode -> value = value;
	newNode -> left = NULL;
	newNode -> right = NULL;

	return newNode;

}

int treeNode :: getValue(){
	return value;
}

int treeNode :: getValue(treeNode* n){
	return n -> value;
}

void treeNode :: setvalue(int val){
	value = val;
	left = NULL;
	right = NULL;
}

int main(){

	int cases;

	cin>>cases;

	switch(cases){

		//The problem is that variables declared in one case are still visible in the subsequent cases unless an explicit { }
		//block is used, but they will not be initialized because the initialization code belongs to another case.
		//hence one can use { } to define scope of the variables in general

		case 0:

		{
			treeNode node1;
			cout<<node1.getValue()<<endl;
			break;
		}


		case 1:
		
		{
			treeNode node2;										//object created on stack and has scope limitation
			treeNode* node3;
			node3 = node2.newNode(5);							//node3 now contains reference to this object node2
			cout<<node2.getValue(node3)<<endl;
			break;			
		}

		case 2:
		/* one can also use new treenode;
		this calls default constructor and creates object on heap.Object is first allocated space
		and then gets automatically initialised with 0 and ref -> method() is the way of calling a method from a object reference
		*/
		
		{
			treeNode* node4 = new treeNode();																							
			cout<<node4->getValue()<<endl;							
			break;
		}

		case 3:
		{
			treeNode node5;											//allocates space for object but no initialization so garbage value is printed
			cout<<node5.getValue()<<endl;
			break;
		}

		case 4:
		{
			treeNode node6;											//allocates space and then we are setting value via public method
			node6.setvalue(8);
			cout<<node6.getValue()<<endl;
			break;
		}

		default :

		{	
			cout<<"This is default option"<<endl;
		}

	}

	return 0;
}