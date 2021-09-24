#include <bits/stdc++.h>
#include <string.h>
using namespace std;
 
// function to find minimum elements needed.
int minElements(int arr[], int n)
{
    int halfSum = 0;
    for (int i = 0; i < n; i++)
        halfSum = halfSum + arr[i];   

    sort(arr, arr + n, greater<int>());
 
    int res = 0, curr_sum = 0;
    for (int i = 0; i < n; i++) {
 
        curr_sum += arr[i];
        res++;
        halfSum=halfSum-arr[i];
 
        // current sum greater than sum
        if (curr_sum > halfSum)        
            return res;
    }
    return res;
}
 
// Driver function
int main()
{
    int arr[] = {2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minElements(arr, n) << endl;
    return 0;
}