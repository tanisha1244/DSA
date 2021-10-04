#include <iostream>
#include <algorithm>
using namespace std;
 
// Find the minimum number formed by doing at-most `k` swap operations upon
// digits of the string
void findMin(string s, int k, string &min_so_far)
{
    // compare the current number with a minimum number so far
    if (min_so_far.compare(s) > 0) {
        min_so_far = s;
    }
 
    // base case: no swaps left
    if (k < 1) {
        return;
    }
 
    int n = s.length();
 
    // do for each digit in the input string
    for (int i = 0; i < n - 1; i++)
    {
        // compare the current digit with the remaining digits
        for (int j = i + 1; j < n; j++)
        {
            // if the digit at i'th index is more than the digit at j'th index
            if (s[i] > s[j])
            {
                // swap `s[i]` and `s[j]`
                swap(s[i], s[j]);
 
                // recur for remaining `k-1` swap
                findMin(s, k - 1, min_so_far);
 
                // backtrack: restore the string
                swap(s[i], s[j]);
            }
        }
    }
}
 
// Wrapper over findMin() function
string findMinimum(string s, int k)
{
    string min = s;
 
    findMin(s, k, min);
    return min;
}
 
int main()
{
    // input string and number
    string s = "934651";
    int k = 2;
 
    string min = findMinimum(s, k);
 
    cout << "The minimum number formed by doing at-most " << k
         << " swaps is " << min;
 
    return 0;
}