#include <iostream>
#include <vector>
using namespace std;

void merge_sort_algorithm(vector<int>&,int,int);
void merger(vector<int>&,int,int,int);
void display(vector<int>&);
int main(){
	vector<int> arr= {9,8,6,4,3,2,1};

	merge_sort_algorithm(arr,0,arr.size()-1);
	display(arr);
}
void merge_sort_algorithm(vector<int>& a,int l,int r){

	if(r>l){
		int m= l + (r-l)/2;
		merge_sort_algorithm(a,l,m);
		merge_sort_algorithm(a,m+1,r);
		merger(a,l,m,r);
	}
}

void merger(vector<int>&a,int l,int m,int r){

	//calculating length of individual halfs which are needed to be merged
	int first_half_length = m-l+1;
	int second_half_length = r-m;

	//creating temporary storage for these arrays
	int first_half[first_half_length];
	int second_half[second_half_length];

	//filling up the temporary arraay with values
	for(int i=0;i<first_half_length;i++){
		first_half[i]=a[l+i];    // note that the mth element is include in first array i.e arr[m]
	}
	for(int i=0;i<second_half_length;i++){
		second_half[i]=a[m+1+i];
	}
 	int i=0,j=0,k=l;   				// i for first array and j for second array and k for final array

	while(i<first_half_length&&j<second_half_length){
		if(first_half[i]<=second_half[j]){
			a[k]=first_half[i];
			i++;
		}
		else{
			a[k]=second_half[j];
			j++;
		}
		k++;
	}

	//copy if there are some remaining elements
	while(i<first_half_length){
		a[k]=first_half[i];
		i++;
		k++;
	}
	while(j<second_half_length){
		a[k]=second_half[j];
		j++;
		k++;
	}
}

void display(vector<int>& a){
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}