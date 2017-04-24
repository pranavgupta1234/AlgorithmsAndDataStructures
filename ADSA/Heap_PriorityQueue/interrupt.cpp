#include <iostream>
#include <string>
#include "PriorityQueue.hpp"
using namespace std;

class interrupt{

private:

	int device_id;
	int burst_time;
	int delay;
	int priority_value;
	string status;

public:

	interrupt();														//required for call to new interruot inside list header 

	interrupt(const int did,const int bt,const int d,const int pv);

	bool operator>(const interrupt& inter){
		return (priority_value > inter.priority_value ? true : false) ;		//as MinProrityQueue uses operator > and it is defined for int,double		
	}																		//we have to overload the operator for our custom class

	bool operator<(const interrupt& inter){
		return (priority_value < inter.priority_value ? true : false) ;		//as MinProrityQueue uses operator > and it is defined for int,double		
	}																		//we have to overload the operator for our custom class

	void operator=(const interrupt& i){
		device_id = i.device_id;
		burst_time = i.burst_time;
		delay = i.delay;
		priority_value = i.priority_value;
		status = i.status;
	}

	int getDeviceID(){
		return device_id;
	}

	int getPriority(){
		return priority_value;
	}

	int getBurstTime(){
		return burst_time;
	}

	int getDelay(){
		return delay;
	}

	void setBurstTime(int bt){
		this -> burst_time = bt;
	}

	void setStatus(string st){
		status = st;
	}

	string getStatus(){
		return status;
	}

	void display(){

		cout<<device_id<<"\t";
		cout<<burst_time<<"\t\t";
		cout<<delay<<"\t\t";
		cout<<priority_value<<"\t\t";
		cout<<status<<"\n";
	}

};

interrupt :: interrupt(){

	this -> device_id = 0;
	this -> burst_time = 0;
	this -> delay = 0;
	this -> priority_value = 0;	
}

interrupt :: interrupt(const int did,const int bt,const int d,const int pv){
	
	this -> device_id = did;
	this -> burst_time = bt;
	this -> delay = d;
	this -> priority_value = pv;
	status = "QUEUED";	
}

int main(){

	cs202::MinPriorityQueue<interrupt> interrupts;
	interrupt DEVICE_TASK;
	int total_burst_time=0;
	int total_delay_time=0;
	int id,burst_t,delay_t,priority;
	int no_of_interrupts;
	int cpu_priority = 10;
	cout<<"Enter the number of interrupts you have :: ";
	cin>>no_of_interrupts;

	while(no_of_interrupts--){

		cout<<"Enter the DeviceID 	Enter Burst Time 	Enter Delay 	Enter Priority"<<endl;
		cin>>id>>burst_t>>delay_t>>priority;
		total_delay_time += delay_t;

		cout<<"\nID\tBurst Time\tDelay Time\tPriority\tStatus\n";

		while(!interrupts.empty()){
				
			DEVICE_TASK = interrupts.minimum();
				
			if(DEVICE_TASK.getBurstTime() <= total_delay_time){

				DEVICE_TASK = interrupts.extract_min();
				DEVICE_TASK.setStatus("DONE");

				total_delay_time -= DEVICE_TASK.getBurstTime();
				total_burst_time -= DEVICE_TASK.getBurstTime();

				DEVICE_TASK.display();
			}else{
				break;
			}
		}

		if(total_burst_time >= total_delay_time){
			if(!interrupts.empty() and interrupts.minimum().getPriority() > priority){
				interrupts.minimum().setStatus("Pre-Empted");
				interrupts.minimum().setBurstTime(interrupts.minimum().getBurstTime() - total_delay_time);
				total_burst_time -= total_delay_time;
				total_delay_time = 0;
			}
		}

		interrupts.insert(interrupt(id, burst_t, delay_t, priority));
		total_burst_time += burst_t;
		

		interrupts.minimum().setStatus("In Progress");

		cout<<"\nLoaded Tasks in Processor";
		cout<<"\nID\tBurst Time\tDelay Time\tPriority\tStatus\n";

		while(!interrupts.empty()){
			interrupts.extract_min().display();
		}

		cout<<"\n";
		char e;
		cout<<"Exit(y/n) : ";
		cin>>e;

		if(e == 'y' || e == 'Y'){

			cout<<"\nID\tBurst Time\tDelay Time\tPriority\tStatus\n";
			while(!interrupts.empty()){

				DEVICE_TASK = interrupts.extract_min();
				DEVICE_TASK.setStatus("Completed");

				DEVICE_TASK.display();
			}

			exit(EXIT_SUCCESS);			
		}

	}

	return 0;
}
