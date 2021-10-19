class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int dp[n+1];
       dp[0]=0;
       dp[1]=arr[0];
       dp[2]=arr[0]>arr[1]?arr[0]:arr[1];
       
       for(int i=3;i<=n;i++){
           dp[i]=max(arr[i-1]+dp[i-2],dp[i-1]);
       }
       return dp[n];
    }
};