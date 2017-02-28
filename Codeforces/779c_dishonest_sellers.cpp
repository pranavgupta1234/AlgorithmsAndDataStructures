#include <iostream>
#include <utility>					//make_pair
#include <algorithm>				//sort
#include <vector>
#include <map>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int temp;
	int sum=0;
	vector<int> current;
	vector<int> after;

	for(int i=0;i<n;i++){
		cin>>temp;
		current.push_back(temp);
	}

	//In case we definitely know the size of vector we can avoid calling the function of template class as it will add to time complexity
	for(int i=0;i<n;i++){
		cin>>temp;
		sum+=temp;
		after.push_back(current[i]-temp);
	}
	/*map[key] = value; there's no way to tell if you replaced the value for key, or if you created a new key with value, map::insert() will only create */

	sort(after.begin(),after.end());

	for(int i=0;i<k||after[i]<0;i++){
		sum+=after[i];
	}

	cout<<sum<<endl;

	return 0;
}

/* How to use pairs in cpp
// pair::pair example
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

int main () {
  std::pair <std::string,double> product1;                     // default constructor
  std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  std::pair <std::string,double> product3 (product2);          // copy constructor

  product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

  product2.first = "shoes";                  // the type of first is string
  product2.second = 39.90;                   // the type of second is double

  std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
  
  also vector<pair<int,int>> can also be declared
*/