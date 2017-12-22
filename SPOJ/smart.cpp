// C++ implementation to find n'th smart number
#include<bits/stdc++.h>
using namespace std;
 
// Limit on result
const int MAX = 3000;
 
// Function to calculate n'th smart number
int smartNumber(int n)
{
    // Initialize all numbers as not prime
    int primes[MAX] = {0};
 
    // iterate to mark all primes and smart number
    vector<int> result;
 
    // Traverse all numbers till maximum limit
    for (int i=2; i<MAX; i++)
    {
        // 'i' is maked as prime number because
        // it is not multiple of any other prime
        if (primes[i] == 0)
        {
            primes[i] = 1;
 
            // mark all multiples of 'i' as non prime
            for (int j=i*2; j<MAX; j=j+i)
            {
                primes[j] -= 1;
 
                // If i is the third prime factor of j
                // then add it to result as it has at
                // least three prime factors.
                if ( (primes[j] + 3) == 0)
                    result.push_back(j);
            }
        }
    }
 
    // Sort all smart numbers
    sort(result.begin(), result.end());
 
    // return n'th smart number
    return result[n-1];
}
 
// Driver program to run the case
int main()
{
    int n;
    cin>>n;
    cout << smartNumber(n);
    return 0;
}