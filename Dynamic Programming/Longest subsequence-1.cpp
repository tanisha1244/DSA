class Solution{
public:
    int longestSubsequence(int n, int a[])
    {
        int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if ((a[i] == a[j] + 1) || (a[i] == a[j] - 1))
 
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int r = 1;
    for (int i = 0; i < n; i++)
        {
            r=max(r,dp[i]);
        }
    return r;
    }
};//O(N*2)
  //O(N)