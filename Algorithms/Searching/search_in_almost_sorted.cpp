#include <iostream>
#include <vector>
using namespace std;

int search_in_almost_sorted(vector<int>&,int l,int r,int x);

int main(){

	int temp;
	//almost sorted array (the element which should be at a[i] can be at a[i-1] or a[i+1] also)
	vector<int> a = {1,2,4,3,5,6,7,9,8,10};

    cout<<"Search element : ";
    cin>>temp;

	cout<<search_in_almost_sorted(a,0,a.size(),temp);
	cout<<endl;
}

int search_in_almost_sorted(vector<int>& arr,int l,int r,int x){

	if(r>=l){
		int mid = l + (r-l)/2;		
		if( arr[mid] == x)  return mid;
		else if(mid<r && arr[mid+1]==x) return (mid+1);
		else if(mid>l && arr[mid-1]==x) return (mid-1);
		else if(x>arr[mid]) return search_in_almost_sorted(arr,mid+2,r,x);
		else return search_in_almost_sorted(arr,l,mid-2,x);
	}
	return -1;
}